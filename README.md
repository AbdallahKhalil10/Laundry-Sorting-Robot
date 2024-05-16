# Robotic Arm Color Sorting Project
## Overview
This project is a robotic arm system that uses a TCS3200 color sensor to detect colors and sorts clothes accordingly. The robotic arm utilizes servo motors (Servo 9966 and LF-20MG) for movement. The project leverages the servo and servoSmooth libraries to control the servos and perform precise movements.

## Features
Color Detection: Uses the TCS3200 color sensor to detect colors based on the combination of red, green, and blue pulse widths.
Robotic Arm: Equipped with Servo 9966 and LF-20MG servos to pick and sort clothes.
Smooth Servo Movements: Implements various functions to ensure smooth and accurate movements using the servo and servoSmooth libraries.
## Hardware Components
TCS3200 Color Sensor: Detects the color of the clothes.
Servo 9966: One of the servos used for the robotic arm's movement.
LF-20MG Servo: Another servo used for the robotic arm's movement.
## Software Libraries
servo: Used for controlling the servo motors.
servoSmooth: Used to ensure smooth movements of the servos.
## Installation
### Prerequisites
Arduino IDE installed on your computer.
The servo and servoSmooth libraries installed in the Arduino IDE.
Library Installation
Open the Arduino IDE.
Go to Sketch -> Include Library -> Manage Libraries.
In the Library Manager, search for servo and servoSmooth.
Click on each library and install them.
