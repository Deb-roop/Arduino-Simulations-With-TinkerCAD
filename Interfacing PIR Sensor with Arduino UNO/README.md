# 🚨 Motion Detection with PIR Sensor and Arduino UNO

This project demonstrates how to interface a **PIR Motion Sensor** with an **Arduino UNO** to detect motion and control an **LED** as an alert. The circuit is simulated using **Tinkercad**, and the system outputs motion detection status to both an LED and the Serial Monitor.

---

## 🔧 Hardware Required

- Arduino UNO  
- PIR Motion Sensor (e.g., HC-SR501)  
- LED  
- 220Ω Resistor  
- Breadboard  
- Jumper Wires  
- USB Cable  

---

## 🔌 Circuit Overview

| Component | Arduino Pin |
|----------|-------------|
| PIR OUT  | D13         |
| LED +ve  | D12         |
| LED -ve  | GND (via 220Ω resistor) |
| PIR VCC  | 5V          |
| PIR GND  | GND         |

<img width="773" height="669" alt="image" src="https://github.com/user-attachments/assets/9b485d81-3733-4790-868e-5803f515a4ab" />


---

## 🧠 Code Explanation

### 1. Complete Arduino Code

```cpp
#define pir 13 
bool pir_val = 0;
#define led 12

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
}

void loop() {
  pir_val = digitalRead(pir);
  if (pir_val == HIGH) {
    Serial.println("Motion Detected");
    digitalWrite(led, HIGH);
  } else {
    Serial.println("No Motion Detected");
    digitalWrite(led, LOW);
  }
}
```

---

### 2. Pin Definitions

- `pir` is defined as digital pin 13 — connected to the output pin of the PIR sensor.  
- `led` is defined as digital pin 12 — connected to the LED's anode (long leg).  
- `pir_val` is a boolean variable that stores the sensor reading (`HIGH` or `LOW`).

---

### 3. setup() Function

```cpp
void setup() {
  Serial.begin(9600);       // Initialize Serial Monitor
  pinMode(led, OUTPUT);     // Set LED pin as OUTPUT
  pinMode(pir, INPUT);      // Set PIR sensor pin as INPUT
}
```

- Initializes the Serial Monitor for debugging.  
- Configures the LED pin as OUTPUT and the PIR sensor as INPUT.

---

### 4. loop() Function

```cpp
void loop() {
  pir_val = digitalRead(pir);       // Read PIR sensor state

  if (pir_val == HIGH) {            // If motion is detected
    Serial.println("Motion Detected");
    digitalWrite(led, HIGH);        // Turn ON LED
  } 
  else {
    Serial.println("No Motion Detected");
    digitalWrite(led, LOW);         // Turn OFF LED
  }
}
```

- Reads the state of the PIR sensor.  
- If motion is detected (`HIGH`), the LED turns ON and a message is printed.  
- If not, the LED turns OFF and a different message is printed.

---

### 5. How It Works

The PIR sensor detects changes in infrared radiation (such as human movement).  
When motion is detected:
- The sensor sends a HIGH signal to Arduino.  
- The Arduino turns on an LED and prints "Motion Detected" to the Serial Monitor.  

When there's no motion:
- The sensor sends a LOW signal.  
- The Arduino turns the LED off and prints "No Motion Detected".

---

## ✅ To Do

- Add a buzzer for audible alerts.  
- Log detection timestamps to an SD card or EEPROM.  
- Use a relay to trigger real-world devices (like a light bulb or alarm).

---

## 🧑‍💻 Author

Built by 
<p>
DEBROOP GHOSH DOSTIDER <br>
ECE - KUET
</p>
— follow for more beginner-friendly Arduino and Tinkercad projects!

---

## 📄 License

This project is open-source under the **MIT License**. Use it freely in personal, academic, or commercial projects.
