# 🌧️ Automatic-RainShutter-IOT-Project
The Automatic Rain Shutter Project is a sensor-based system that automatically opens or closes shutters based on rain detection. Using a rain sensor and microcontroller, the system protects buildings or rooms from rain damage without manual intervention.  
This project integrates hardware and IoT technology to provide an efficient, cost-effective, and smart solution for rain protection.

# 🎯 Objectives

* Automatically detect rain using sensors.
* Control shutter movement using a motor.
* Send real-time data to IoT platforms (ThingSpeak).
* Display data on a mobile application.
* Reduce manual effort and improve protection against rain.

# ⚙️ Components Used
## 🔧 Hardware

* ESP32 Microcontroller (ESP32-WROOM-32)
* Rain Sensor
* Moisture Sensor
* Servo Motor (9g Micro Servo)
* BME280 Sensor
* Power Supply
* Connecting Wires

## 💻 Software & Tools

* Arduino IDE (ESP32 Programming)
* ThingSpeak (IoT Cloud Platform)
* Android Studio / Flutter (Mobile App)
* Serial Monitor

# 🏗️ System Architecture
## Working Principle

* Rain sensor detects rainfall.
* ESP32 processes sensor data.
* Servo motor closes the shutter when rain is detected.
* Shutter opens automatically when rain stops.
* Data is sent to ThingSpeak.
* Mobile app fetches and displays real-time data.

# 🔄 Workflow

* Rain detected → Shutter closes automatically
* Rain stops → Shutter opens automatically
* Sensor data → Sent to ThingSpeak
* Data → Displayed on Mobile App

# 🌐 IoT Integration

* ESP32 publishes sensor data to ThingSpeak.
* Mobile app fetches data from ESP32 or ThingSpeak.
* Real-time monitoring of weather conditions.

# ✅ Features

* Fully automatic operation
* Real-time monitoring
* Energy-efficient design
* IoT-enabled system
* Customizable for different windows/shutters
* Cost-effective solution

# 📊 Applications

* Homes and buildings
* Offices
* Smart homes
* Outdoor equipment protection
* Industrial environments

# 🧠 Advantages

* No manual intervention required
* Quick response to rain
* Improved safety and protection
* Smart and scalable design

# 📸 Project Demo
![Automatic Rain Shutter](rainshutter.png)
