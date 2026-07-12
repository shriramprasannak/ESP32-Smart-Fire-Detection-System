\# 🔥 ESP32 Smart Fire Detection and Automatic Emergency Response System



\## 📌 Project Overview



This project demonstrates an ESP32-based Smart Fire Detection and Automatic Emergency Response System using the Wokwi simulation platform.



The system continuously monitors temperature, simulated smoke level, and flame detection. Based on the environmental conditions, the ESP32 automatically classifies the system into Safe, Warning, or Fire Emergency mode.



During a fire emergency, the system activates a buzzer, relay module, red LED, and emergency servo motor to simulate an automatic emergency response.



Real-time temperature, smoke level, flame status, system status, and emergency response information are displayed through the Serial Monitor.



\---



\## ✨ Features



\- Real-time temperature monitoring using DHT22

\- Flame detection using a flame sensor module

\- Simulated smoke level monitoring using a potentiometer

\- Three automatic operating modes

\- LED-based system status indication

\- Piezo buzzer emergency alarm

\- Automatic relay activation during fire emergency

\- Servo-based emergency response mechanism

\- Real-time Serial Monitor output

\- ESP32-based embedded system implementation



\---



\## 🚦 Operating Modes



\### 🟢 Safe Mode



When the environmental conditions are normal:



\- Temperature is below 45°C

\- Smoke level is below 50%

\- Flame is not detected

\- Green LED is ON

\- Emergency response is OFF



!\[Safe Mode Output](Safe\_Mode\_Output.png)



\---



\### 🟡 Warning Mode



The system enters Warning Mode when:



\- Temperature is 45°C or above



OR



\- Smoke level is 50% or above



During Warning Mode:



\- Yellow LED is ON

\- Buzzer provides a warning alert

\- Emergency response remains in standby mode

\- Relay remains OFF

\- Servo remains at its normal position



!\[Warning Mode Output](Warning\_Mode\_Output.png)



\---



\### 🔴 Fire Emergency Mode



The system enters Fire Emergency Mode when:



\- Flame is detected



OR



\- Temperature is 60°C or above and smoke level is 70% or above



During Fire Emergency Mode:



\- Red LED is ON

\- Piezo buzzer is activated

\- Relay module is activated

\- Emergency servo rotates to 90°

\- Emergency response becomes active



!\[Fire Emergency Output](Fire\_Emergency\_Output.png)



\---



\## ⚙️ Working Principle



1\. The DHT22 sensor continuously measures temperature.



2\. The potentiometer simulates the smoke concentration level.



3\. The flame sensor monitors the presence of flame.



4\. The ESP32 reads all sensor inputs and evaluates environmental conditions.



5\. Under normal conditions, the system operates in Safe Mode.



6\. When temperature or smoke exceeds the warning threshold, the system enters Warning Mode.



7\. When flame is detected or critical temperature and smoke conditions occur, the system enters Fire Emergency Mode.



8\. During a fire emergency, the buzzer and relay are activated.



9\. The emergency servo rotates to simulate an automatic emergency mechanism.



10\. Real-time sensor values and system status are displayed on the Serial Monitor.



\---



\## 🧰 Components Used



| Component | Quantity |

|---|---|

| ESP32 DevKit V1 | 1 |

| DHT22 Temperature and Humidity Sensor | 1 |

| Potentiometer Module | 1 |

| Flame Sensor Module | 1 |

| Piezo Buzzer | 1 |

| Relay Module | 1 |

| Servo Motor | 1 |

| Green LED | 1 |

| Yellow LED | 1 |

| Red LED | 1 |

| 220 Ω Resistor | 3 |

| Jumper Wires | As required |



The complete component list is available in:



\[View Components List](Components\_List.csv)



\---



\## 📷 Circuit Design



The complete Wokwi circuit design is shown below:



!\[Circuit Design](Circuit\_Design.png)



The Wokwi circuit configuration and wiring information are available in:



\[View Wokwi Diagram Configuration](diagram.json)



\---



\## 📄 Schematic Diagram



The complete schematic and GPIO wiring connection diagram is available here:



\[View Schematic Diagram](Schematic\_Diagram.pdf)



\---



\## 💻 ESP32 Code



The complete ESP32 program is available in:



\[View ESP32 Code](ESP32\_Smart\_Fire\_Detection\_System.ino)



\---



\## 🔌 ESP32 Pin Configuration



| Component | ESP32 Pin |

|---|---|

| DHT22 SDA | GPIO 15 |

| Smoke Potentiometer SIG | GPIO 34 |

| Flame Sensor DO | GPIO 27 |

| Flame Sensor AO | GPIO 35 |

| Servo Motor PWM | GPIO 18 |

| Relay Module IN | GPIO 19 |

| Piezo Buzzer | GPIO 23 |

| Green LED | GPIO 25 |

| Yellow LED | GPIO 26 |

| Red LED | GPIO 33 |



\---



\## 📊 Serial Monitor Output



The Serial Monitor displays real-time sensor readings and system status.



\### 🟢 Safe Mode Output



!\[Safe Mode Output](Safe\_Mode\_Output.png)



\### 🟡 Warning Mode Output



!\[Warning Mode Output](Warning\_Mode\_Output.png)



\### 🔴 Fire Emergency Output



!\[Fire Emergency Output](Fire\_Emergency\_Output.png)



\---



\## 🛠️ Software Used



\- Wokwi ESP32 Simulator

\- Arduino C/C++

\- DHT Sensor Library for ESPx

\- ESP32Servo Library



\---



\## 🎯 Applications



\- Smart building fire monitoring systems

\- Industrial fire detection systems

\- Warehouse safety monitoring

\- Home automation and fire safety

\- Embedded emergency response systems

\- IoT-based safety system prototypes

\- Fire detection research prototypes



\---



\## 🚀 Future Improvements



\- Integrate a real smoke or gas sensor

\- Add Wi-Fi-based emergency notifications

\- Send alerts through Telegram or email

\- Implement IoT cloud monitoring

\- Add GPS-based emergency location tracking

\- Integrate a water sprinkler control system

\- Add an OLED or LCD display

\- Implement mobile application monitoring

\- Store sensor data in a cloud database

\- Add machine learning-based fire prediction



\---



\## 👨‍💻 Author



\*\*Shriram Prasanna K\*\*



B.Tech Electronics and Communication Engineering



\---



\## 📜 Note



This project is a simulation-based prototype developed using Wokwi.



The potentiometer is used to simulate smoke concentration levels. The emergency response mechanisms are implemented for educational, embedded systems, and fire safety demonstration purposes.

