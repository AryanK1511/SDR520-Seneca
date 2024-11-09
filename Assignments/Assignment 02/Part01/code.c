#pragma config(StandardModel, "RVW SQUAREBOT")

// ========== CALIBRATIONS ==========

float KSonarSensorThreshold = 35;
float KStandardSpeed = 150;
float KWaitTimeMS = 1000;

// ========== CONSTANTS ==========

const float CAngleDegrees = 90;

// ========== UTILITY FUNCTIONS ==========

void resetEncoders();
void stopMotors();
void startMotors(float leftMotorSpeed, float rightMotorSpeed);
bool wallDetected();
void moveForward();
void returnToCenter(bool fromRight);
void turnRight(float angleDegrees);
void turnLeft(float angleDegrees);
float checkSpaceOnRight(float angleDegrees);
float checkSpaceOnLeft(float angleDegrees);
void positionByDirection(float angleDegrees);
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

// Function to move forward
void moveForward() {
  while (!wallDetected()) {
    startMotors(KStandardSpeed, KStandardSpeed);
  }
  stopMotors();
}

// Function to center the robot and bring it back to the direction where it
// started from
void returnToCenter(bool fromRight) {
  if (fromRight) {
    while (SensorValue(rightEncoder) < 0) {
      startMotors(-KStandardSpeed, KStandardSpeed);
    }
  } else {
    while (SensorValue(leftEncoder) < 0) {
      startMotors(KStandardSpeed, -KStandardSpeed);
    }
  }
  stopMotors();
}

// Function to turn the robot right by a certain angle
void turnRight(float angleDegrees) {
  while ((abs(SensorValue(leftEncoder)) / (angleDegrees * 4)) < 1) {
    motor[rightMotor] = -KStandardSpeed;
    motor[leftMotor] = KStandardSpeed;
  }
  stopMotors();
  wait1Msec(500);
}

// Function to turn the robot left by a certain angle
void turnLeft(float angleDegrees) {
  while ((abs(SensorValue(rightEncoder)) / (angleDegrees * 4)) < 1) {
    motor[leftMotor] = -KStandardSpeed;
    motor[rightMotor] = KStandardSpeed;
  }
  stopMotors();
  wait1Msec(500);
}

// Function to check space on the right using sonar sensor
float checkSpaceOnRight(float angleDegrees) {
  turnRight(angleDegrees);
  return SensorValue(sonarSensor);
}

// Function to check space on the left using sonar sensor
float checkSpaceOnLeft(float angleDegrees) {
  turnLeft(angleDegrees);
  return SensorValue(sonarSensor);
}

// Function to decide the direction that the robot should head in
void positionByDirection(float angleDegrees) {
  float spaceOnRight = checkSpaceOnRight(angleDegrees);
  returnToCenter(true);
  float spaceOnLeft = checkSpaceOnLeft(angleDegrees);

  if (spaceOnRight > spaceOnLeft) {
    returnToCenter(false);
    turnRight(angleDegrees);
  }
}

// Function to detect if there was any collision using touch sensor
bool isCollision() { return SensorValue(touchSensor) == 1; }

// ========== MAIN PROGRAM ==========
task main() {
  while (!isCollision()) {
    moveForward();
    wait1Msec(KWaitTimeMS);
    resetEncoders();
    positionByDirection(CAngleDegrees);
  }
}