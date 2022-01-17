# Multi-Sensor Integrated Security System

## Overview
The Multi-Sensor Integrated Security System is a comprehensive security solution designed for detecting various environmental and intrusion indicators such as gas leaks, unauthorized access, and proximity of objects. The system utilizes a combination of sensors interfaced with an ARM LPC2148 microcontroller and a SIM900 GSM module for real-time alerts.

## Hardware Requirements
- **ARM LPC2148 Microcontroller:** Serves as the core processing unit for managing sensors and communications.
- **SIM900 GSM Module:** Used for sending SMS alerts.
- **KY-038 Microphone Sound Sensor Module:** Detects sound levels for potential break-ins or loud disturbances.
- **MQ-2 Gas/Smoke Sensor:** Monitors for gas leaks or smoke, indicating potential fire hazards.
- **TTP223 Capacitive Touch Sensor:** Detects touch or physical interactions for unauthorized access.
- **HC-SR04 Ultrasonic Sensor:** Measures the proximity of objects or individuals, useful for detecting presence in restricted areas.

## Software Requirements
- Any C/C++ IDE that supports ARM development (e.g., Keil µVision, ARM mbed, etc.)
- Serial communication software for debugging (e.g., PuTTY, Tera Term)

## Connection Diagram
To connect the components, follow this general guideline. Please refer to each component's datasheet for more specific connection information.

### SIM900 GSM Module
- **TXD:** Connect to RXD pin of LPC2148
- **RXD:** Connect to TXD pin of LPC2148
- **GND:** Connect to Ground of the power source and LPC2148
- **VCC:** Connect to a 5V power source

### KY-038 Microphone Sound Sensor
- **AO (Analog Output):** Connect to an Analog pin on LPC2148 (e.g., AD0.0)
- **GND:** Connect to Ground
- **VCC:** Connect to 3.3V on LPC2148

### MQ-2 Gas/Smoke Sensor
- **A0 (Analog Output):** Connect to an Analog pin on LPC2148 (e.g., AD0.1)
- **GND:** Connect to Ground
- **VCC:** Connect to 5V

### TTP223 Capacitive Touch Sensor
- **OUT:** Connect to a digital I/O pin on LPC2148 (e.g., P0.1)
- **GND:** Connect to Ground
- **VCC:** Connect to 3.3V

### HC-SR04 Ultrasonic Sensor
- **TRIG:** Connect to a digital I/O pin on LPC2148 (e.g., P0.2)
- **ECHO:** Connect to a digital I/O pin on LPC2148 (e.g., P0.3) through a voltage divider (to bring down 5V to 3.3V)
- **GND:** Connect to Ground
- **VCC:** Connect to 5V

## Software Setup
1. **Environment Setup:** Install your preferred ARM development environment and configure it for LPC2148 development.
2. **Project Import:** Clone this repository and open the project in your development environment.
3. **Library Configuration:** Ensure the libraries in the `lib` directory are included in your project path.
4. **Build:** Compile the project. Address any compilation issues if they arise.
5. **Upload:** Connect your LPC2148 to your computer and upload the compiled binary.

## Usage
Once the system is powered on and initialized, it will continuously monitor the connected sensors. If any sensor triggers an alert condition (as defined in `main.cpp`), the system will send an SMS to the predefined phone number with a message indicating which sensor was triggered.

## Customization
You can customize the threshold values and alert messages in `main.cpp` to suit your specific requirements. For more advanced customizations, consider modifying the sensor libraries or adding new functionality in the `lib` directory.

## Contributing
Contributions to this project are welcome. Please consider following these steps:
1. Fork the repository.
2. Create a new branch for your feature or fix.
3. Commit your changes with descriptive messages.
4. Push your changes to your fork.
5. Submit a pull request to the main repository.

## License
This project is open-sourced under the MIT License. See the LICENSE file for more details.
