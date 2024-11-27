#pragma config(StandardModel, "RVW CLAWBOT")

// ========== CALIBRATIONS ==========



// ========== GLOBAL VARIABLES ==========

float locationOfClosestObject = 0;

// ========== CONSTANTS ==========

float CCmsPerFoot = 30.48;
float CArenaWidthHeightFeet = 6;

// Function to stop all motors
void stopMotors() {
	motor[rightMotor] = 0;
  motor[leftMotor] = 0;
}

// Function to change the motor speed
void adjustMotorSpeed(float leftMotorSpeed, float rightMotorSpeed) {
	motor[leftMotor] = leftMotorSpeed;
	motor[rightMotor] = rightMotorSpeed;
}

// Function to set the robot in a start position such that it doesn't detect the wall
void setStartPosition() {
		while (abs(SensorValue[gyro]) < 100)
  {
    adjustMotorSpeed(-100, 100);
  }
}

float getLocationOfClosestObject() {
	float minDistanceFromObject = SensorValue[sonarSensor];
	// float targetAngle = SensorValue[gyro];

  while (abs(SensorValue[gyro]) < 710) {
  	if (SensorValue[sonarSensor] < minDistanceFromObject) {
  		minDistanceFromObject = SensorValue[sonarSensor];
  		// targetAngle = SensorValue[gyro];
  	}
    adjustMotorSpeed(-40, 40);
  }

  //stopMotors();

   // return targetAngle;
  return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	setStartPosition();
	stopMotors();
	wait1Msec(2000);
  getLocationOfClosestObject();
  stopMotors();
}