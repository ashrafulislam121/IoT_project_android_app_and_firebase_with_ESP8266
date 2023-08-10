
# Building a Smart Classroom Door System with ESP8266: A DIY Guide


## Introduction
The Smart Classroom Door System is designed to enhance classroom management and communication between teachers and students. It leverages the power of the ESP8266 microcontroller, Firebase Realtime Database, and a variety of sensors and actuators to create a seamless experience.
## Key Features
1. Presence Detection and Alert Mechanism
The project utilizes an ultrasonic sensor that detects the presence of students in front of a teacher’s chamber door. Upon detection, a buzzer is activated briefly, alerting the teacher to the presence of someone outside.

2. Interactive Communication via Android App
The Android app developed using MIT App Inventor/Kodular serves as the central control hub for teachers and students. It features buttons like “enter,” “wait,” and “close” that trigger messages displayed on a MAX7219 dot matrix display located outside the door.



Teacher Android App and Student Android App
3. Teacher’s Remote Control
Teachers can manage their classroom environment remotely using the app. They can turn on/off lights, fans, AC, or other devices in their room, promoting energy efficiency and convenience.

4. Status Checking for Students
Students can use the app to check whether the teacher is in the room or not, enhancing transparency and minimizing disruptions during class.

5. Custom Messaging
Teachers can send custom messages or notices via the app, which are instantly displayed on the dot matrix display outside the door.
## Components and Technology
The project utilizes several hardware components, including the ESP8266 microcontroller, an ultrasonic sensor for presence detection, a buzzer for alerts, and a MAX7219 dot matrix display for message display. The integration of these components is facilitated by the Arduino IDE for programming and SPI communication.
## Pin Configuration
The project utilizes different pins on the ESP8266 microcontroller to connect and control various hardware components. Here’s a breakdown of the pin configuration and their respective roles:

Ultrasonic Sensor:
trigPin (D4): Connected to the trigger pin of the ultrasonic sensor. It sends out ultrasonic pulses to measure distance.
echoPin (D3): Connected to the echo pin of the ultrasonic sensor. It receives the reflected ultrasonic pulses.
2. Buzzer:

buzz (D2): Connected to the buzzer, which emits sound alerts when triggered.
3. MAX7219 Dot Matrix Display:

CLK_PIN (D5): Connected to the clock pin of the MAX7219 display, facilitating data synchronization.
DATA_PIN (D7): Connected to the data pin of the MAX7219 display, transmitting data to the display.
CS_PIN (D8): Connected to the chip select pin of the MAX7219 display, enabling communication with the display.
4. LED Indicators:

D0: Connected to an LED indicator, serving as a sample representation of lights, fans, or other loads.
## Code Overview
The project’s code is a blend of C and C++ programming, tailored to the ESP8266 microcontroller. It establishes a connection to the WiFi network and Firebase Realtime Database. Firebase enables real-time synchronization of data between the hardware and the Android app.

The code is structured to handle multiple functionalities, such as detecting the presence, triggering alerts, receiving messages from the app, and controlling the display. The ultrasonic sensor is employed to measure distance, while the buzzer emits alerts based on predefined conditions.
## Learning and Achievement
The project showcases the creator’s in-depth understanding of both hardware and software development. It highlights the use of SPI communication, sensor integration, cloud-based databases, and mobile app development.
## Conclusion
The Smart Classroom Door System demonstrates the fusion of creativity and technology in the educational setting. By leveraging the ESP8266 microcontroller, Firebase Realtime Database, and a range of sensors and actuators, this project offers teachers and students a unique and interactive experience. It exemplifies how innovative thinking can reshape conventional practices and elevate classroom management to new heights.






## Screenshots

![App Screenshot](https://miro.medium.com/v2/resize:fit:640/format:webp/1*HFr5DmC8YdXZycvCpT7hcw.jpeg)

![App Screenshot](https://miro.medium.com/v2/resize:fit:4800/format:webp/1*zwzSzDRi7lQxtEK9LguQdQ.jpeg)

![App Screenshot](https://miro.medium.com/v2/resize:fit:640/format:webp/1*3b7SoVIS8_FyAHOO1MYZhQ.jpeg)

![App Screenshot](https://miro.medium.com/v2/resize:fit:640/format:webp/1*TX8YzJ7Kn-jKeMWiNDceBQ.jpeg)







