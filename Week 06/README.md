# Week 06 Notes

## 1D, 2D, and 3D Finders

- **1D Finders**: Typically measure distance in a single axis or dimension. These sensors are simpler but limited in the spatial information they can provide.
- **2D Finders**: Can scan in two dimensions, commonly used in mapping or localization tasks.
- **3D Finders**: Capture data in three dimensions, creating a 3D map of the environment, often using sensors like Lidar or 3D cameras.

## Lidar Sensor

- **Overview**: Lidar (Light Detection and Ranging) is a remote sensing technology similar to sonar (uses sound waves) and radar (uses radio waves). It uses **time of flight** measurements to determine distances by sending out laser pulses and measuring the time it takes for them to return after reflecting off an object.
- **Types**:

  - **Airborne Lidar**: Typically used in aviation to map large areas like topography and forests.
  - **Mobile Lidar**: Mounted on vehicles or drones for mapping environments, often used for autonomous driving.

- **Capabilities**:

  - Can detect multiple returns (or echoes) from a single laser pulse, which allows for the analysis of layers (e.g., tree canopies, ground).
  - Used for mapping topography and structure by generating a **point cloud**, which is a collection of 3D points representing the environment.

- **Advantages and Disadvantages of Radar vs. Lidar**:

  - **Lidar**: Higher resolution and precision, but can be affected by weather conditions like rain, fog, or dust.
  - **Radar**: Lower resolution but better performance in adverse weather conditions.

## Audio Speech Sensor

- **Functionality**: Used for recognizing and processing spoken language. Often part of voice-controlled systems and can be integrated into virtual assistants, home automation, and robotics.
- **Applications**: Speech recognition, command interpretation, and real-time communication in smart devices and robots.

## Environmental Sensors

- **Purpose**: These sensors detect changes in environmental conditions such as temperature, humidity, air quality, and atmospheric pressure.
- **Common Applications**: Climate control, pollution monitoring, and agricultural automation.

## Movement Sensors

- **Types**: Can include accelerometers, gyroscopes, and motion detectors.
- **Applications**: Used to detect and track movement, whether it's the motion of a person, a robot, or parts of a system. Often used in robotics, gaming, and fitness devices.

## Pose Estimation

- **Definition**: Refers to estimating the position and orientation (pose) of an object or person. Pose estimation is crucial in robotics and computer vision for tracking movement or interaction with the environment.

- **Methods**: Utilizes sensors like cameras, Lidar, and IMUs (Inertial Measurement Units) to calculate poses. Often implemented in applications like humanoid robots, augmented reality, and motion capture.

## RFID Scanner

- **Functionality**: RFID (Radio Frequency Identification) uses electromagnetic fields to automatically identify and track tags attached to objects.
- **Applications**: Commonly used for inventory management, access control, and tracking goods in logistics.

## Speed Sensor

- **Purpose**: Measures the velocity or speed of an object. Often used in robotics, automotive applications (speed monitoring), and industrial machinery.
- **Types**: Can be implemented using Doppler radar, Lidar, or optical encoders.

## Microcontrollers

- **Definition**: A small computer on a single integrated circuit, typically used in embedded systems. It contains a processor, memory, and input/output peripherals.

- **Common Microcontrollers**:
  - **Arduino**: Popular for prototyping and small-scale projects.
  - **ESP32**: Used for IoT applications, has built-in Wi-Fi and Bluetooth capabilities.
  - **Raspberry Pi**: Not exactly a microcontroller but often used for more complex embedded projects.
