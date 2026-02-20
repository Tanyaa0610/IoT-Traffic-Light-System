# IoT-Traffic-Light-System
# Smart Traffic Light System using Arduino

## Project Description
This project simulates a smart traffic light system using Arduino UNO
on Wokwi Simulator.

- Green, Yellow and Red LEDs turn ON for 10 seconds cyclically
- Ultrasonic Sensor detects vehicle crossing RED signal
- Buzzer alerts when RED light is crossed
- OLED Display shows warning message

## Components Used
- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- SSD1306 OLED Display
- Buzzer
- LEDs

## Working
During RED light:
If distance < 10cm
→ Buzzer turns ON  
→ OLED displays "Red Light Crossed"

## 🔗 Simulation Link
[Simulation](https://wokwi.com/projects/455855790113933313)
