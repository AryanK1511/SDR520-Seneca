# Using Sensors

**SIL levels** refer to **Safety Integrity Levels**, which are used to evaluate the reliability and safety of safety-related systems in various industries, particularly in automation, control systems, and functional safety engineering.

SIL levels are defined by the **International Electrotechnical Commission (IEC)** in the standard **IEC 61508**, which provides a framework for the functional safety of electrical, electronic, and programmable electronic safety-related systems.

There are four SIL levels, ranging from **SIL 1** to **SIL 4**. The higher the SIL level, the greater the level of safety and reliability required:

- **SIL 1**: Low risk, basic safety requirements.
- **SIL 2**: Moderate risk, enhanced safety requirements.
- **SIL 3**: High risk, significant safety requirements.
- **SIL 4**: Very high risk, stringent safety requirements.

## Choosing a sensor

- What do you need the robot to sense?
- Where will your robot be operating?
- What is your budget?

**Parameters:**

- Application
- Cost
- Environment
- Range
- Field of view

**Sensors can be of different types:**

- Contact Sensors
- Non-contact sensors
- Position and velocity Sensors

## IP Rating of a sensor

**IP ratings** (Ingress Protection ratings) are used to classify the degree of protection provided by enclosures against the intrusion of solid objects (like dust) and liquids (like water). These ratings are particularly important for sensors and electronic devices used in various environments, as they indicate their robustness and suitability for specific applications. Here are some key points to understand about IP ratings:

### Structure of IP Ratings

1. **Format**: The IP rating typically consists of the letters "IP" followed by two digits:

   - Example: **IP67**

2. **Digits**:

   - **First Digit (0-6)**: Represents the level of protection against solid objects (dust, dirt, etc.).

     - **0**: No protection.
     - **1**: Protected against objects larger than 50 mm (e.g., hands).
     - **2**: Protected against objects larger than 12.5 mm (e.g., fingers).
     - **3**: Protected against objects larger than 2.5 mm (e.g., tools).
     - **4**: Protected against objects larger than 1 mm (e.g., wires).
     - **5**: Dust-protected (limited ingress of dust).
     - **6**: Dust-tight (no ingress of dust).

   - **Second Digit (0-8)**: Represents the level of protection against liquids.
     - **0**: No protection.
     - **1**: Protected against vertically falling drops of water.
     - **2**: Protected against water droplets falling at an angle up to 15°.
     - **3**: Protected against spraying water at an angle up to 60°.
     - **4**: Protected against splashing water from any direction.
     - **5**: Protected against water jets from any direction.
     - **6**: Protected against strong water jets.
     - **7**: Protected against immersion in water up to 1 meter for 30 minutes.
     - **8**: Protected against immersion in water beyond 1 meter (usually specified by the manufacturer).

### Importance of IP Ratings

1. **Environmental Suitability**: IP ratings help determine if a sensor or device is suitable for specific environments, such as outdoor applications, industrial settings, or areas exposed to moisture.

2. **Durability**: Higher IP ratings generally indicate greater durability and reliability, which can lead to lower maintenance costs and increased lifespan of the device.

3. **Application Selection**: Knowing the IP rating helps engineers and designers select appropriate components for applications, ensuring they meet the necessary protection requirements.

4. **Compliance**: Many industries have standards and regulations that require specific IP ratings for equipment, especially in hazardous or extreme conditions.

### Examples of Common IP Ratings

- **IP65**: Dust-tight and protected against low-pressure water jets from any direction. Suitable for outdoor use in light rain.
- **IP67**: Dust-tight and protected against immersion in water up to 1 meter for 30 minutes. Ideal for devices exposed to significant moisture.
- **IP68**: Dust-tight and protected against continuous immersion in water beyond 1 meter. Suitable for submersible applications.

## Digital vs Analog values

**Analog** and **digital values** are two fundamental types of signals used in electronics and computing to represent information.

### Analog Values

1. **Definition**: Analog values represent continuous signals that can take on any value within a given range. They are often used to measure physical quantities like temperature, light intensity, or sound.

2. **Characteristics**:

   - **Continuous Range**: Analog signals can vary smoothly and can take any value (within limits). For example, the voltage from a temperature sensor might range continuously from 0V to 5V.
   - **Infinite Resolution**: Because they can take on an infinite number of values, analog signals can provide a very precise representation of a variable.
   - **Waveform Representation**: Analog signals are often represented as waveforms, showing how the signal changes over time (e.g., sine waves, square waves).

3. **Examples**:

   - Thermocouples (temperature measurement)
   - Potentiometers (variable resistance)
   - Audio signals (sound waves)

4. **Applications**: Analog signals are commonly used in audio and video equipment, sensors, and control systems where continuous signals are needed.

### Digital Values

1. **Definition**: Digital values represent discrete signals that can take on a finite number of values, typically in binary (0s and 1s). Digital signals are used to represent data in a form that can be processed by computers and digital systems.

2. **Characteristics**:

   - **Discrete Levels**: Digital signals can only take on specific values (e.g., in a binary system, these are usually 0 and 1). For example, a digital temperature sensor might output a value of 23°C as a binary representation.
   - **Finite Resolution**: Digital signals have a limited resolution based on how many discrete levels they can represent. The more bits used, the higher the resolution (e.g., an 8-bit digital signal can represent 256 levels).
   - **Robustness**: Digital signals are less susceptible to noise and interference compared to analog signals, making them more reliable for transmission and processing.

3. **Examples**:

   - Digital temperature sensors (e.g., DS18B20)
   - Microcontrollers (e.g., Arduino, Raspberry Pi)
   - Digital audio formats (e.g., MP3, WAV)

4. **Applications**: Digital signals are widely used in computing, telecommunications, and digital media, as well as in any application requiring precise and reliable data representation.

### Key Differences

| Aspect                  | Analog Values                         | Digital Values                       |
| ----------------------- | ------------------------------------- | ------------------------------------ |
| Signal Type             | Continuous                            | Discrete                             |
| Value Range             | Infinite values within a range        | Finite values (e.g., binary 0 and 1) |
| Representation          | Waveforms (smooth variations)         | Binary (0s and 1s)                   |
| Resolution              | Infinite (limited by physical limits) | Finite (based on bit depth)          |
| Susceptibility to Noise | More susceptible to noise             | Less susceptible to noise            |
| Applications            | Sensors, audio, and video equipment   | Computing, digital communications    |

## Incremental and Absolute Encoders

**Incremental** and **absolute encoders** are types of rotary or linear position sensors used to measure the position, speed, and direction of moving parts in various applications, including robotics, automation, and industrial machinery.

### Incremental Encoders

1. **Definition**: Incremental encoders provide information about the movement of a shaft or object in the form of incremental counts. They measure changes in position rather than the absolute position.

2. **Operation**:

   - Incremental encoders generate a series of pulses as the shaft rotates. Each pulse corresponds to a specific amount of movement (e.g., one pulse per degree of rotation).
   - They typically have two output channels, known as **A** and **B**, which are 90 degrees out of phase. This allows for the determination of both the direction of rotation and the amount of movement.
   - The output can be a square wave or a series of pulses that can be counted by a microcontroller or other processing unit.

3. **Characteristics**:

   - **Relative Positioning**: Provides position information relative to a starting point. If power is lost, the encoder will not remember its position until it is re-referenced.
   - **High Resolution**: The resolution depends on the number of pulses per revolution (PPR); higher PPR values result in more precise measurements.
   - **Speed Measurement**: Can be used to measure speed by counting the number of pulses over a fixed time interval.

4. **Applications**:
   - Robotics (joint position feedback)
   - CNC machines
   - Conveyor systems
   - Servo motor control

### Absolute Encoders

1. **Definition**: Absolute encoders provide a unique digital code for each position of the shaft, allowing for the absolute position to be known at all times, even after power loss.

2. **Operation**:

   - Absolute encoders use a combination of multiple tracks and sensors to generate a unique binary or gray code for each position.
   - The output typically consists of multiple bits (e.g., 12-bit, 16-bit) representing the position of the shaft directly without needing to count pulses.
   - They can be either single-turn (measuring within one rotation) or multi-turn (measuring over multiple rotations).

3. **Characteristics**:

   - **Absolute Positioning**: Always provides the exact position of the shaft, even if power is lost or the system is reset.
   - **No Homing Required**: There is no need to reference the encoder's position after a power cycle, making them easier to use in some applications.
   - **Higher Complexity**: Generally more complex and expensive than incremental encoders due to the additional circuitry and coding schemes.

4. **Applications**:
   - Robotics (robot arm positioning)
   - Industrial automation (process control)
   - Aerospace (flight control systems)
   - Medical devices (robotic surgery)

### Key Differences

| Aspect             | Incremental Encoders                   | Absolute Encoders                         |
| ------------------ | -------------------------------------- | ----------------------------------------- |
| Positioning Type   | Relative positioning                   | Absolute positioning                      |
| Power Loss         | Loses position information             | Retains position information              |
| Output Type        | Pulses (incremental counts)            | Unique code for each position             |
| Complexity         | Simpler and less expensive             | More complex and generally more expensive |
| Homing Requirement | Requires homing after power loss       | No homing required                        |
| Resolution         | Depends on pulses per revolution (PPR) | Depends on the number of bits used        |

## Extras

- Gyro sensors(Gyroscopic sensors) are capable of sensing movements that are difficult for humans to detect, such as rotation and changes in orientation.
