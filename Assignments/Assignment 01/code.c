#pragma config(StandardModel, "RVW Mammalbot")

// ========== CALIBRATION VARIABLES ==========

// At this distance, we know that we need to start turning the bot in some
// direction
float K_sonar_threshold_distance_cm = 50;

// ========== CONSTANTS ==========

// Ref Doc for robot specifications:
// https://www.robotc.net/teaching_rc_vex_iq/lesson/media_files/PalmIslandGuide.pdf
float C_wheel_diameter_cm = 7.35;
float C_wheel_base_length_cm = 16;
float C_encoder_pulses_per_rev = 360;
float C_wheel_circumference_cm = PI * C_wheel_diameter_cm;

// ========== REGULAR VARIABLES ==========

// This variable increments at every turn so that we know whether to turn left
// or right For this current program, we turn left when this var is 0 and 1 and
// right when this is 2
int turn_count = 0;
// Turn 90 degrees
float turn_angle = 90;
// Calculate arc length for a turn
float arc_length = (PI * C_wheel_base_length_cm) * (turn_angle / 360);

// 360 pulses = 2 * PI * r cms
// 1 cm = 360 / (2*PI*r) pulses
// arc_length cms = arc_length * (360/(2*PI*r)) cms
int required_turn_ticks =
    arc_length * (C_encoder_pulses_per_rev / C_wheel_circumference_cm);

// ========== UTILITY FUNCTIONS ==========

// Function to reset the left and right encoders
void reset_encoders() {
  SensorValue[leftEncoder] = 0;
  SensorValue[rightEncoder] = 0;
}

// Function to check whether there was a collision
bool is_collision() { return SensorValue(touchSensor) == 1; }

// ========== MOBILITY FUNCTIONS ==========

// Function to stop the robot from moving
void stop_robot() {
  motor[leftMotor] = 0;
  motor[rightMotor] = 0;
}

// Function to move the robot in a straight line
void move_robot() {
  motor[leftMotor] = 80;
  motor[rightMotor] = -80;
}

// Function to turn left
void turn_left(int ticks) {
  reset_encoders();
  while (fabs(SensorValue[rightEncoder]) < ticks) {
    motor[leftMotor] = 50;
    motor[rightMotor] = -80;
  };
};

// Function to turn right
void turn_right(int ticks) {
  reset_encoders();
  while (fabs(SensorValue[leftEncoder]) < ticks) {
    motor[leftMotor] = 80;
    motor[rightMotor] = -50;
  }
}

// ========== MAIN FUNCTION ==========

task main() {
  while (!(is_collision())) {

    // Move in a straight line if the robot is not too close to the wall
    while (SensorValue(sonarSensor) > K_sonar_threshold_distance_cm) {
      move_robot();
    };

    // If the robot is close to the wall, then turn
    while (SensorValue(sonarSensor) <= 50 && SensorValue(sonarSensor) != -1) {
      // Turn left twice before turning right to complete the course
      if (turn_count != 2) {
        turn_left(required_turn_ticks);
      } else {
        turn_right(required_turn_ticks);
      };
    };

    // Increment the turn counter every time the robot turns to know which
    // direction to turn in
    turn_count += 1;
  };

  // Stop the robot in case of a collision
  stop_robot();
}