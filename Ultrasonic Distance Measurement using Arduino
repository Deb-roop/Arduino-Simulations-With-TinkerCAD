# 📏 Ultrasonic Distance Measurement using Arduino

This project uses the **HC-SR04 ultrasonic sensor** with an **Arduino Uno** to measure the distance to nearby objects in real-time. The sensor sends out ultrasonic pulses and calculates the distance based on the time it takes for the echo to return. The result is continuously printed to the **Serial Monitor**.

---

## 🧰 Required Components

- Arduino Uno board  
- HC-SR04 Ultrasonic Sensor  
- Jumper wires  
- Breadboard (optional)  
- USB cable (for power and uploading code)

---

## ⚙️ How It Works

1. The **Trig** pin sends out a 10 µs ultrasonic pulse.
2. When the pulse hits an object, it reflects back to the **Echo** pin.
3. The time taken for the echo to return is measured.
4. The distance is calculated using the formula:

Distance = (Time × Speed of Sound) / 2

Speed of sound ≈ 0.034 cm/µs.

---

## 🔍 Working Principle

- The ultrasonic sensor works like sonar: it emits a sound wave and listens for the echo.
- `digitalWrite()` is used to trigger the pulse.
- `pulseIn()` measures how long the echo took to return.
- `Serial.print()` displays the distance in centimeters in the **Serial Monitor**.
- The process repeats every 200 milliseconds to continuously update the measurement.

---



