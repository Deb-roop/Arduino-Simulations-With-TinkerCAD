# 🔄 Interfacing Servo Motor with Arduino UNO using Tinkercad

This project demonstrates how to control a **servo motor** using an **Arduino UNO** in **Tinkercad**. The servo rotates smoothly from 0° to 180° and back, creating a continuous sweeping motion.

---

## 🔧 Hardware Required

- Arduino UNO  
- Servo Motor (e.g., SG90)  
- Breadboard  
- Jumper Wires  
- USB Cable (for code upload)

---

## 🔌 Circuit Overview

| Component      | Arduino Pin | Description                    |
|----------------|-------------|--------------------------------|
| Servo Signal   | D7          | PWM signal to control angle    |
| Servo VCC      | 5V          | Power supply for the motor     |
| Servo GND      | GND         | Ground connection              |
<img width="791" height="509" alt="image" src="https://github.com/user-attachments/assets/270fa081-c40f-49a2-beaf-a7e99993c36f" />

---

## 🧠 Code Explanation

### 1. Complete Arduino Code

```cpp
#include <Servo.h>     // Include Servo motor control library

Servo Myservo;         // Create servo object to control the motor
int pos;               // Variable to store the current angle

void setup() {
  Myservo.attach(7);   // Attach the servo to pin 7
}

void loop() {
  // Move from 0° to 180°
  for (pos = 0; pos <= 180; pos++) {
    Myservo.write(pos);    // Move servo to current angle
    delay(15);             // Wait for servo to reach the position
  }
  delay(3000);             // Pause at 180° for 3 seconds

  // Move back from 180° to 0°
  for (pos = 180; pos >= 0; pos--) {
    Myservo.write(pos);    // Move servo to current angle
    delay(15);
  }
  delay(1000);             // Pause at 0° for 1 second
}
```

---

### 2. setup() Function

```cpp
void setup() {
  Myservo.attach(7);   // Connect servo control wire to pin 7
}
```

- Initializes the servo and sets up the signal pin.
- The servo is now ready to receive angle instructions.

---

### 3. loop() Function

```cpp
void loop() {
  for (pos = 0; pos <= 180; pos++) {
    Myservo.write(pos);
    delay(15);
  }
  delay(3000);

  for (pos = 180; pos >= 0; pos--) {
    Myservo.write(pos);
    delay(15);
  }
  delay(1000);
}
```

- The first `for` loop sweeps the servo from 0° to 180° with a smooth transition.
- The `delay(3000)` holds the servo at 180° for 3 seconds.
- The second `for` loop moves it back to 0°.
- A short `delay(1000)` is used before repeating the cycle.

---

## ⚙️ How It Works

A servo motor receives a PWM signal that tells it what angle to rotate to. In this project:

- The **Servo library** handles PWM signal generation.
- The servo is controlled via **pin 7**.
- The motor rotates between **0° and 180°** and back in a loop.

This simulates a basic robotic sweeping mechanism, useful in projects like obstacle scanners, robotic arms, or automatic sensors.

---

## ✅ To Do

- Add a potentiometer for manual angle control  
- Use push buttons to set fixed angles (e.g., 0°, 90°, 180°)  
- Expand to control multiple servos for more complex robotics

---

## 🧑‍💻 Author

Created by **DEBROOP GHOSH DOSTIDER (ECE-KUET)**  
Built and tested in **Tinkercad** simulation environment.

---

## 📄 License

This project is open-source under the **MIT License**. Use, modify, and share it freely for learning or development.
