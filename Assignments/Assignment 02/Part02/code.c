#pragma config(StandardModel, "RVW SQUAREBOT")

// ========== CALIBRATIONS ==========

float KSonarSensorThreshold = 50;
float KStandardSpeed = 150;
float KTurnSpeedDiff = 50;
float KBlackLineColorThresholdValue = 800;

// ========== GLOBAL VARIABLES ==========

bool isPositioned = false;

// ========== CONSTANTS ==========

float CTurnAngle = 90;
float x = 10;

// ========== UTILITY FUNCTIONS ==========

void resetEncoders();
void stopMotors();
void stopMotorsSmoothly();
void startMotors(float leftMotorSpeed, float rightMotorSpeed);
bool wallDetected();
void turnLeft(float angleDegrees);
void leaveStartBox();
void stayOnLine();
void findLineandPosition();
bool isCollision();

// Function to reset the encoder values
void resetEncoders() {
  SensorValue[leftEncoder] = 0;
  SensorValue[rightEncoder] = 0;
}

// Function to stop all motors
void stopMotors() {
  motor[rightMotor] = 0;
  motor[leftMotor] = 0;
}

// Function to stop all motors smoothly
void stopMotorsSmoothly() {
  float rightMotorSpeed = motor(rightMotor);
  float leftMotorSpeed = motor(leftMotor);
  while (rightMotorSpeed > 0 && leftMotorSpeed > 0) {
    wait1Msec(20);
    x = leftMotorSpeed;
    leftMotorSpeed -= 1;
    rightMotorSpeed -= 1;
    motor[leftMotor] = leftMotorSpeed;
    motor[rightMotor] = rightMotorSpeed;
  }
}

// Function to start all motors using a predefined speed
void startMotors(float leftMotorSpeed, float rightMotorSpeed) {
  motor[rightMotor] = rightMotorSpeed;
  motor[leftMotor] = leftMotorSpeed;
}

// Function to detect a wall using the sonar sensor
bool wallDetected() {
  return ((SensorValue(sonarSensor) > 0) &&
          (SensorValue(sonarSensor) <= KSonarSensorThreshold))
             ? true
             : false;
}

// Function to turn the robot left by a certain angle
void turnLeft(float angleDegrees) {
  resetEncoders();
  while ((abs(SensorValue(rightEncoder)) / (angleDegrees * 4)) < 1) {
    motor[leftMotor] = -KStandardSpeed;
    motor[rightMotor] = KStandardSpeed;
  }
  stopMotors();
  wait1Msec(500);
}

// Function to leave the start box so that it does not mess up with the line
// follower sensor
void leaveStartBox() {
  startMotors(KStandardSpeed, KStandardSpeed);
  wait1Msec(1500);
}

// Function that makes the robot stay on line once the line is found
void stayOnLine() {
  bool leftSensor =
      SensorValue(leftLineFollower) >= KBlackLineColorThresholdValue;
  bool rightSensor =
      SensorValue(rightLineFollower) >= KBlackLineColorThresholdValue;
  bool centerSensor =
      SensorValue(centerLineFollower) >= KBlackLineColorThresholdValue;

  if (centerSensor) {
    startMotors(KStandardSpeed, KStandardSpeed);
  } else if (leftSensor) {
    startMotors(-KTurnSpeedDiff, KStandardSpeed + KTurnSpeedDiff);
  } else if (rightSensor) {
    startMotors(KStandardSpeed + KTurnSpeedDiff, -KTurnSpeedDiff);
  }
}

// Function that finds the line and positions itself on the line
void findLineandPosition() {
  if (SensorValue(leftLineFollower) > 1200 ||
      SensorValue(rightLineFollower) > 1200 ||
      SensorValue(centerLineFollower) > 1200) {
    wait1Msec(300);
    stopMotors();
    wait1Msec(200);
    turnLeft(CTurnAngle);
    isPositioned = true;
  }
}

// Function to detect if there was any collision using touch sensor
bool isCollision() { return SensorValue(touchSensor) == 1; }

// ========== MAIN PROGRAM ==========
task main() {
  leaveStartBox();

  while (!isPositioned) {
    findLineandPosition();
  }

  while (!isCollision()) {
    stayOnLine();

    if (wallDetected()) {
      stopMotorsSmoothly();
      break;
    }
  }
}