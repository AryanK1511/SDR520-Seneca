# Autonomy in Robotics

## Some important terms

- **Manipulator:** Joints provide linear or rotatory movement.
- **Revolute Configuration:** Five Revolute Joints in vertically articulated configuration.
- **Cartesian Configuration:** Arm movement along three intersecting perpendicular lines.
- **Degrees of freedom:** Refer to the robots movement capabilities in along each axis.
- **Axes of motion:** Linear or angular
- **Agent:** Any system which can be viewed as perceiving its environment through sensors and acting upon it through actuators.

## What is autonomy?

- Ability to make one's own decisions and act on them.
- This means that the robot should take the appropriate actions according to the situation that it is presented with.
- Autonomy could be complete or partial.

## Sensors

- Physical devices that provide information about the world.
- This act of sampling the environment to understand it is called perception.

## Components of Autonomous Robots

- **Effectors:** Any device on the robot that has an impact on the environment.
- **Actuators:** A mechanism that enables the effector to execute an action. They are used for locomotion and manipulation.

## State

State is a description of the robot and its environment.

- It can be:
  - **Observable:** The robot knows its state entirely
  - **Partially Observable:** The robot knows only a part of its state
  - **Hidden:** Does not have any access to its state.
  - **Discrete:** Up, Down ....
  - **Continuous:** Speed

## Levels of autonomy in robots

### Level 0

Not autonomous at all

### Level 1

- A single function is automated but it does not really depend on any factors.
- A car operating on cruise control is a good example of this.

### Level 2

- Use sensory information to make decisions.
- Modersn cars that have automated lane maintenance or collision avoidance are an example of this.

### Level 3

- All safety functions are handled as well.

### Level 4 and 5

- This is fully autonomous.
- Needs no inputs from the driver at all.
- Level 4 are a little limited but 5 can handle more scenarios.
