# Hardware

## End Effectors

- The last link of the robotic arm that interacts with the environment is called an end-effector.
- Could be a gripper or tool.

## Proximity Sensors

- Detect absence or presence of an object.
- Some examples are, Optical, Eddy current, Acoustical and, Touch sensitive proximity sensors.

## Rotatory Encoder

A device that converts the rotational position of a shaft into electrical signals. It is widely used in applications like motor speed feedback, position control, and automation systems.

1. **Pulse Generation**:

   - Encoders use **discs with transparent sections** and a **light-emitting diode (LED)**.
   - As the shaft rotates, the disc interrupts the light, generating a **sequence of pulses**.
   - Each pulse represents a fraction of a revolution, allowing for precise measurement of rotation.

2. **Pulses per Revolution (PPR)**:

   - **PPR** is the number of pulses generated per full rotation of the shaft.
   - A higher PPR provides **greater resolution**, enabling more **accurate position and speed measurements**.

3. **Sense of Rotation**:

   - **Two tracks** (A and B) are used to detect the **direction of rotation** (clockwise or counterclockwise).
   - By comparing the signals from the two tracks, the system can determine the **sense of rotation**.
   - The **leading signal** from one track indicates the direction of movement.

4. **Clockwise vs. Counterclockwise Rotation**:

   - The encoder generates different **signal patterns** depending on the direction.
   - These patterns can be analyzed to control motor direction and adjust position in real-time applications.

5. **Output Measurement**:

   - The output of the rotary encoder is measured as **pulses per revolution**.
   - This output provides feedback for determining the **angular position** or **rotational speed** of the shaft.

6. **Electronics Processing**:
   - The pulses generated by the encoder are fed into electronics (e.g., microcontrollers or PLCs).
   - The electronics process these signals to **calculate position, speed**, and **direction**.
   - The data is then used in automation systems to control machinery.

## Control systems

### **Open-Loop Control System**

An **open-loop control system** is a type of control system in which the control action is independent of the output of the system. In this system, the input is given to the controller, and it produces an output without considering the feedback from the output to adjust its operation. Therefore, the system does not have the ability to correct any errors or deviations from the desired output.

#### **Examples of Open-Loop Control Systems**:

1. **Toaster**: A toaster operates on a set timer. Once you set the timer, it toasts the bread for that duration without measuring the actual toasting level.
2. **Washing Machine (Timer-based)**: A washing machine that runs for a preset duration regardless of the cleanliness of the clothes or the amount of dirt in the water.
3. **Traffic Light Timer**: A traffic light system that changes colors based on a fixed time interval rather than the actual traffic flow.

### **Closed-Loop Control System**

A **closed-loop control system** (also known as a feedback control system) is one in which the control action is dependent on the output of the system. This type of system continuously monitors its output and makes adjustments based on feedback to achieve the desired performance. It effectively uses the output information to minimize errors and maintain the desired system behavior.

#### **Examples of Closed-Loop Control Systems**:

1. **Thermostat-Controlled Heating System**: A thermostat monitors the room temperature and adjusts the heating element based on the difference between the desired and actual temperature.
2. **Cruise Control in Cars**: The cruise control system in vehicles maintains a set speed by adjusting the throttle based on the feedback from the car's speed sensors.
3. **Automatic Voltage Regulator**: This system adjusts the output voltage of a power supply based on the feedback received from the output voltage level to maintain a stable voltage supply.