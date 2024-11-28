#pragma config(StandardModel, "RVW CLAWBOT")

// ========== CONSTANTS ==========

const float ANGLE_THRESHOLD = 130;  						// Threshold angle for positioning the robot
const float ROTATE_LIMIT = 710;     						// Limit for rotating the robot during object search
const float CLOSE_OBJECT_THRESHOLD = 15; 				// Distance threshold for moving towards an object
const float SECOND_CLOSE_OBJECT_THRESHOLD = 20; // Second distance threshold for moving towards an object
const float MAX_DISTANCE = 1000;    						// Maximum distance to check for closest object
const float WAIT_TIME = 250;        						// Default wait time in milliseconds
const float DISTANCE_TO_CHECKPOINT = 182.88;  	// Distance to the checkpoint
const float START_POSITION_WAIT = 1000; 				// Time to wait at start position

// ========== GLOBAL VARIABLES ==========

float calculatedAngle = 0;    									// Final angle used for navigation
float closestObjectAngle = 0;  									// Angle of the closest object
float closestObjectDistance = 0; 								// Distance to the closest object
bool isAtCheckpoint = false;  									// Boolean to check if robot is at the checkpoint

// ========== MOTOR CONTROL FUNCTIONS ==========

// Function to stop all motors
void stopAllMotors() {
    motor[rightMotor] = 0;
    motor[leftMotor] = 0;
}

// Function to set the motor speeds for both motors
void setMotorSpeeds(float leftSpeed, float rightSpeed) {
    motor[leftMotor] = leftSpeed;
    motor[rightMotor] = rightSpeed;
}

// ========== POSITIONING AND NAVIGATION FUNCTIONS ==========

// Function to position the robot at the starting point (avoid wall detection)
void setStartPosition() {
    if (!isAtCheckpoint) {
        while (abs(SensorValue[gyro]) < ANGLE_THRESHOLD) {
            setMotorSpeeds(-20, 20); 
        }
    } else {
        while (abs(SensorValue[gyro]) < ANGLE_THRESHOLD) {
            setMotorSpeeds(20, -20); 
        }
    }
}

// Function to get the location (angle) of the closest object by rotating the robot
void findClosestObjectLocation() {
    float minDistance = MAX_DISTANCE;
    float objectAngle = 0;
    
    if (!isAtCheckpoint) {
        // Rotate the robot and check the distance to find the closest object
        while (abs(SensorValue[gyro]) < ROTATE_LIMIT) {
            if (SensorValue[sonarSensor] != -1 && SensorValue[sonarSensor] < minDistance) {
                minDistance = SensorValue[sonarSensor];
                objectAngle = SensorValue[gyro];
            }
            setMotorSpeeds(-20, 20);
        }
        closestObjectAngle = objectAngle;
        closestObjectDistance = minDistance;
        stopAllMotors();
        wait1Msec(WAIT_TIME);
    } else {
        // Rotate the robot and check the distance to find the closest object
        while (abs(SensorValue[gyro]) < ROTATE_LIMIT) {
            if (objectAngle > 0) {
                break;    
            }
            if (SensorValue[sonarSensor] != -1 && SensorValue[sonarSensor] < minDistance) {
                minDistance = SensorValue[sonarSensor];
                objectAngle = SensorValue[gyro];
            }
            setMotorSpeeds(20, -20);
        }
        closestObjectAngle = objectAngle;
        closestObjectDistance = minDistance;
        wait1Msec(300);
        stopAllMotors();
        wait1Msec(WAIT_TIME);
    }
}

// Function to position the robot to face a specific angle
void turnToAngle(float targetAngle) {
    while (SensorValue[gyro] < targetAngle) {
        setMotorSpeeds(20, -20); // Rotate clockwise
    }
    while (SensorValue[gyro] > targetAngle) {
        setMotorSpeeds(-20, 20); // Rotate counterclockwise
    }
    stopAllMotors();
    wait1Msec(WAIT_TIME);
}

// Function to move the robot forward until it is close to an object (threshold distance)
void moveUntilClose(float distanceThreshold) {
    while (SensorValue[sonarSensor] > distanceThreshold) {
        setMotorSpeeds(50, 50); 
    }
}

// ========== ANGLE CALCULATION AND TURNING FUNCTIONS ==========

// Function to calculate the angle to the checkpoint based on the object's location
void calculateAngleToCheckpoint() {
    float angleToObject = 90 - abs(closestObjectAngle); 
    float horizontalDistance = closestObjectDistance * cosDegrees(angleToObject);  
    float remainingDistance = DISTANCE_TO_CHECKPOINT - horizontalDistance; 
    float verticalDistance = closestObjectDistance * sinDegrees(angleToObject);  
    float angleToCheckpointRad = atan(remainingDistance / verticalDistance);  
    calculatedAngle = radiansToDegrees(angleToCheckpointRad);  
}

// Function to turn the robot by a specified number of degrees (left or right)
void turnDegrees(float degrees, bool isTurningLeft) {
    float initialGyroVal = SensorValue[gyro];
    float temp = initialGyroVal;
    degrees = abs(degrees);

    if (isTurningLeft) {
        while (abs(SensorValue[gyro] - temp) < degrees) {
            setMotorSpeeds(-20, 20); 
        }
    } else {
        while (abs(SensorValue[gyro] - temp) < degrees) {
            setMotorSpeeds(20, -20);
        }
    }

    stopAllMotors();
    wait1Msec(WAIT_TIME);
}

// ========== MAIN TASK ==========

task main() {
    // 01. Move to the start position to avoid detecting the wall
    setStartPosition();
    stopAllMotors(); 
    wait1Msec(START_POSITION_WAIT); 
    
    // 02. Rotate to find the closest object and store its angle
    findClosestObjectLocation();
    stopAllMotors();
    wait1Msec(WAIT_TIME);
    
    // 03. Calculate the angle to the checkpoint using trignometry
    calculateAngleToCheckpoint();
    wait1Msec(WAIT_TIME);
    
    // 04. Turn the robot towards the closest object and move towards it
    turnToAngle(closestObjectAngle);
    stopAllMotors();
    wait1Msec(WAIT_TIME);
    
    // 05. Align the robot towards the obstacle and move towards it
    turnDegrees(200, true);
    moveUntilClose(10);
    stopAllMotors();
    wait1Msec(WAIT_TIME);
    
    // 06. Align parallel to the checkpoint and move straight
    turnToAngle(-900);
    setMotorSpeeds(60, 60);
    wait1Msec(2500);
    stopAllMotors();
    wait1Msec(WAIT_TIME);
    
    // 05. Align the robot towards the checkpoint and move towards it
    turnToAngle(-900 - calculatedAngle);
    moveUntilClose(SECOND_CLOSE_OBJECT_THRESHOLD + 10);
    stopAllMotors();
    wait1Msec(WAIT_TIME);
    
    // 06. Align parallel to the end
    turnToAngle(0);
    stopAllMotors();
    
    // 07. Mark that the robot has reached the checkpoint
    isAtCheckpoint = true;
    wait1Msec(WAIT_TIME);
    
    // 08. Move to the start position to avoid detecting the wall
    setStartPosition();
    stopAllMotors(); 
    wait1Msec(WAIT_TIME); 
    
    // 09. Rotate to find the closest object and store its angle
    findClosestObjectLocation();
    stopAllMotors();
    wait1Msec(WAIT_TIME);
    
    // 10. Calculate the angle to the end position
    calculateAngleToCheckpoint();
    wait1Msec(500);
    
    // 11. Align the robot towards the second obstacle and move towards it
    turnDegrees(100, false);
    wait1Msec(500);
    moveUntilClose(CLOSE_OBJECT_THRESHOLD);
    stopAllMotors();
    wait1Msec(WAIT_TIME);
    
    // 12. Align parallel to the end
    turnToAngle(0);
    stopAllMotors();
    wait1Msec(WAIT_TIME);
    
    // 05. Align the robot towards the end position and move towards it
    turnToAngle(-calculatedAngle);
    wait1Msec(WAIT_TIME);
    stopAllMotors();
    wait1Msec(WAIT_TIME);
    moveUntilClose(20);
    stopAllMotors();
    wait1Msec(WAIT_TIME);
}