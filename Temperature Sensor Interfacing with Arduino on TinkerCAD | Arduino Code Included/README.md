# 🌡️ Temperature Sensor with Arduino on TinkerCAD

This project demonstrates how to interface a temperature sensor (like LM35) with an Arduino using TinkerCAD. It reads the ambient temperature and displays the values on the Serial Monitor.

## 🔧 Components Used
- Arduino Uno  
- LM35 Temperature Sensor (or similar)  
- Breadboard  
- Jumper Wires

## 🧠 Features
- Real-time temperature monitoring  
- Serial output display  
- Simple analog sensor interfacing

## 🖥️ How It Works
1. The LM35 sensor outputs an analog voltage based on the temperature.  
2. The Arduino reads this analog signal using `analogRead()`.  
3. The voltage is converted to temperature in Celsius.  
4. The result is displayed via the Serial Monitor.
