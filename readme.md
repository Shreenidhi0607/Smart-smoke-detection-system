# Smart Smoke Detection and Evacuation System

This project is an Arduino-based safety system that detects fire and harmful smoke
using multiple sensors and automatically activates ventilation and alerts.

The system uses MQ2, Flame Sensor, and DHT11 to reduce false alarms and improve
detection accuracy.

---

## Features
- Multi-sensor fire and smoke detection
- Automatic window opening using servo motor
- Fan activation using relay module
- Smoke filtration using activated carbon filter
- Buzzer and LED alert system
- Real-time monitoring through Serial Monitor


---

## Components Used
- Arduino UNO
- MQ2 Gas Sensor
- DHT11 Temperature Sensor
- Flame Sensor
- Servo Motor
- Relay Module
- DC Fan
- Buzzer
- LED
- 9V Battery
- Breadboard and Jumper Wires
- Activated Carbon Filter


---

## Pin Configuration

| Component     | Arduino Pin |
|---------------|-------------|
| MQ2 Sensor    | A0          |
| Flame Sensor  | D2          |
| LED           | D3          |
| Servo Motor   | D6          |
| Relay Module  | D7          |
| Buzzer        | D9          |
| DHT11 Sensor  | D12         |

---

## Working Principle

1. The MQ2 sensor detects harmful smoke and gas.
2. The flame sensor detects the presence of fire.
3. The DHT11 measures temperature.
4. When two or more sensors detect abnormal conditions, the system considers it a hazard.
5. The relay activates the exhaust fan.
6. The servo motor opens the window flap.
7. The buzzer and LED alert nearby people.
8. When conditions return to normal, the system resets automatically.

---

## Smoke Filtration System

An activated carbon filter is placed near the exhaust fan to filter harmful gases
and smoke particles before releasing air outside. This helps in reducing air
pollution and improves indoor air quality during fire or smoke incidents.


## Circuit Diagram

Refer to the image in the Circuit folder for wiring details.

---

## Hardware Prototype

Images of the real hardware setup are available in the Images folder.

---

## How to Run the Project

1. Connect all components according to the circuit diagram.
2. Upload the Arduino code from the Code folder.
3. Power the Arduino using USB.
4. Power the fan using an external 9V battery.
5. Open Serial Monitor at 9600 baud rate to view sensor readings.

---

## Applications
- Home fire safety systems
- Industrial smoke monitoring
- Laboratory safety
- Smart building automation

---

## Future Improvements
- IoT-based remote monitoring
- Mobile alert system
- LCD display for real-time data
- Cloud data logging

---

## Author

Shreenidhi S
Avanthiga S U

## Simulation Note

Due to limitations of Tinkercad in handling external power sources, relays, and DC motors
together, full simulation of this project may not run properly. The circuit was tested
on real hardware, where it worked as expected.

