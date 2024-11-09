#pragma config(StandardModel, "RVW SQUAREBOT")

// ========== CALIBRATION VARIABLES ==========

// Speed of the robot when it moves straight (for initial line finding)
int K_straight_movement_speed = 100;

// Reduced base speed for line following to prevent overshooting
int K_base_speed = 100;

// Increased turn differential for sharper turns
int K_turn_speed_differential = 50;

// ========== CONSTANTS ==========

float C_black_line_color_threshold_value = 1000;
int C_encoder_pulses_per_rev = 360;

// ========== Variables ==========
int spins = 0;
bool power_on = true;

// ========== FUNCTION DEFINITIONS ==========
void move_forward();
void find_line();
bool line_detected();
void follow_line();
void adjust_motors(int leftSpeed, int rightSpeed);
void stop_motors();
void gradual_stop_if_wall();
void stop_if_collision();

// +++++ ==================== MAIN FUNCTION ==================== +++++
task main() {
  find_line();
  stop_motors();
  wait1Msec(500);

  while (power_on) {
    follow_line();
    //  gradual_stop_if_wall();
    // stop_if_collision();
  }
}

// ========== FUNCTIONS ==========
void move_forward() {
  motor[leftMotor] = K_straight_movement_speed;
  motor[rightMotor] = K_straight_movement_speed;
}

void stop_motors() {
  motor[leftMotor] = 0;
  motor[rightMotor] = 0;
}

void adjust_motors(int leftSpeed, int rightSpeed) {
  if (leftSpeed > 100)
    leftSpeed = 100;
  if (rightSpeed > 100)
    rightSpeed = 100;
  if (leftSpeed < -100)
    leftSpeed = -100;
  if (rightSpeed < -100)
    rightSpeed = -100;

  motor[leftMotor] = leftSpeed;
  motor[rightMotor] = rightSpeed;
}

void find_line() {
  while (spins < 2) {
    spins = SensorValue[leftEncoder] / C_encoder_pulses_per_rev;
    move_forward();
  }

  while (!line_detected()) {
    motor[leftMotor] = K_base_speed;
    motor[rightMotor] = K_base_speed;
  }
}

bool line_detected() {
  return (SensorValue(leftLineFollower) >= C_black_line_color_threshold_value ||
          SensorValue(centerLineFollower) >=
              C_black_line_color_threshold_value ||
          SensorValue(rightLineFollower) >= C_black_line_color_threshold_value);
}

void follow_line() {
  bool leftSensor =
      SensorValue(leftLineFollower) >= C_black_line_color_threshold_value;
  bool centerSensor =
      SensorValue(centerLineFollower) >= C_black_line_color_threshold_value;
  bool rightSensor =
      SensorValue(rightLineFollower) >= C_black_line_color_threshold_value;

  if (centerSensor) {
    adjust_motors(K_base_speed, K_base_speed);
  } else if (leftSensor) {
    adjust_motors(-K_turn_speed_differential,
                  K_base_speed + K_turn_speed_differential);
  } else if (rightSensor) {
    adjust_motors(K_base_speed + K_turn_speed_differential,
                  -K_turn_speed_differential);
  } else {
    stop_motors();
    wait1Msec(100);

    while (!line_detected()) {
      adjust_motors(K_base_speed / 2, -K_base_speed / 2);
      wait1Msec(10);
    }
  }
}

void gradual_stop_if_wall() {
  while (SensorValue(sonarSensor) < 40) {
    adjust_motors(motor(leftMotor) - 20, motor(rightMotor) - 20);
  }
  power_on = false;
}

void stop_if_collision() {
  if (SensorValue(touchSensor) == 1) {
    stop_motors();
    power_on = false;
  }
}