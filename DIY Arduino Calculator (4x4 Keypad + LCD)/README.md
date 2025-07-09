# 📟 DIY Arduino Calculator Using LCD and Keypad

This project demonstrates how to create a basic calculator using an **Arduino Uno**, a **4x4 matrix keypad**, and a **16x2 LCD display**. It supports operations like addition, subtraction, multiplication, and division — all handled with hardware input and output!

---

## 🔧 Hardware Required

- Arduino Uno (or compatible)
- 16x2 LCD Display
- 4x4 Matrix Keypad
- Jumper Wires
- Breadboard or Custom PCB
- USB Cable for Uploading Code
 ## 🔌 Circuit Overview
 **LCD Pin Mapping:**

| LCD Pin | Arduino Pin |
|---------|-------------|
| RS      | 13          |
| E       | 12          |
| D4      | 11          |
| D5      | 10          |
| D6      | 9           |
| D7      | 8           |

**Keypad Connection:**

| Keypad Rows | Arduino Pins | Keypad Columns | Arduino Pins |
|-------------|--------------|----------------|---------------|
| R1          | 7            | C1             | 3             |
| R2          | 6            | C2             | 2             |
| R3          | 5            | C3             | 1             |
| R4          | 4            | C4             | 0             |

 <img> ![image](https://github.com/user-attachments/assets/e17898fe-6a46-46f0-9b22-eb790e9bd138) </img>
<h1>🧠 Code Explanation</h1>

### 1. Libraries Used
```cpp
#include <Keypad.h>
#include <LiquidCrystal.h>
```

- `Keypad.h`: Handles input from the 4x4 matrix keypad.
- `LiquidCrystal.h`: Manages the 16x2 LCD screen.

### 2. LCD Setup
Initializes the LCD using the specified Arduino digital pins.
```cpp
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // Initialize the LCD with pins: rs, en, d4, d5, d6, d7
```
### 3. Keypad Layout
Defines the layout of keys and assigns characters to each button (numbers and operators).
 ```cpp
// Keypad matrix setup
// Define number of rows and columns on the keypad
const byte ROWS = 4;   // 4 rows
const byte COLS = 4;   // 4 columns

// Define the characters on the keypad in a 2D matrix format
char customkeys[ROWS][COLS] = {
  {'1', '2', '3', '+'},   // Row 1
  {'4', '5', '6', '-'},   // Row 2
  {'7', '8', '9', '*'},   // Row 3
  {'C', '0', '=', '/'}    // Row 4
};
// Define which Arduino pins are connected to the keypad's row and column pins
byte rowPins[ROWS] = {7, 6, 5, 4};    // Connect to the 4 row pins of the keypad
byte colPins[COLS] = {3, 2, 1, 0};    // Connect to the 4 column pins of the keypad
```
## 4. Create the Keypad object 
```cpp
// Create the keypad object using the defined layout and pin connections
Keypad customkeypad = Keypad(makeKeymap(customkeys), rowPins, colPins, ROWS, COLS);
```
### 5. Define variables
```cpp
// Define variables used for calculator operations
String input = "";      // To hold the number being entered as a string
char operation;         // To store the selected operator: +, -, *, or /
float num1, num2;       // To store the two operands
float result;           // To store the result after calculation
```
### 6. Void Setup Function
```cpp
void setup() {
  // Initialize the 16x2 LCD screen
  // This sets the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Set the cursor to the first row and first column (0,0)
  // This is the top-left corner of the LCD
  lcd.setCursor(0, 0);

  // Display the first welcome message on the first row
  lcd.print("DIY Calculator");

  // Move the cursor to the second row and first column (0,1)
  lcd.setCursor(0, 1);

  // Display the instruction for the user on the second row
  lcd.print("Enter numbers:");

  // Wait for 4 seconds (4000 milliseconds) so the user can read the message
  delay(4000);

  // Clear the LCD screen to prepare for user input
  lcd.clear();
}
```
### 7. Voidloop function :
## a. Reading Input:
```cpp
// The loop function runs continuously after setup()
void loop() {
  // Read the key that was just pressed on the keypad
  char customkey = customkeypad.getKey();
```
Waits for a key press from the keypad.

## b. Number Entry:
- Appends the digit or decimal point to the input string.
- Updates the LCD with the current number.
```cpp
// If a key was pressed
  if (customkey) {
    
    // If the key is a number (0–9) or decimal point '.'
    if ((customkey >= '0' && customkey <= '9') || customkey == '.') {
      input += customkey;                 // Append the character to the current input string
      lcd.setCursor(0, 0);                // Set cursor to first row
      lcd.print(input);                   // Display current input
    }
  ```
## c. Operator Selection:
- Stores the first number (num1).
- Clears the input and waits for the second number.
- Displays the operation on the LCD.
```cpp
// If the key is one of the operations: +, -, *, /
    else if (customkey == '+' || customkey == '-' || customkey == '*' || customkey == '/') {
      num1 = input.toFloat();             // Convert the current input to a floating-point number
      input = "";                         // Clear the input for the second number
      operation = customkey;              // Store the selected operator

      lcd.clear();                        // Clear the screen
      lcd.print(num1);                    // Show first number
      lcd.print(" ");                     
      lcd.print(operation);               // Show selected operation (e.g., +)
    }
```
## d. Calculate Result:
- Converts the second number.
- Executes the arithmetic operation.
- Displays the result on the second line of the LCD.

```cpp
// If the '=' key is pressed, perform the calculation
    else if (customkey == '=') {
      num2 = input.toFloat();             // Convert second number from string to float
      input = "";                         // Clear input

      lcd.clear();                        // Clear LCD to display result

      // Perform the correct operation based on the operator selected
      switch (operation) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = (num2 != 0) ? num1 / num2 : 0; break;  // Avoid divide by zero
      }

      lcd.print("Result:");               // Display result header
      lcd.setCursor(0, 1);                // Move to second line
      lcd.print(result);                  // Show the result
    }
```
## e. Clear Input:
- Clears the screen and resets the current input.
 ```cpp
 // If the 'C' key is pressed, clear all inputs and the screen
    else if (customkey == 'C') {
      input = "";                         // Clear stored input
      lcd.clear();                        // Clear LCD display
    }
```
### ✅ To Do
- Add support for negative numbers
- Add support for decimal inputs (currently partially supported)
- Optimize error handling (e.g., divide by 0)
### 🧑‍💻 Author
Built by DEBROOP GHOSH DOSTIDER (KUET-ECE) — follow me for more Arduino projects!
### 📄 License
This project is open-source under the MIT License.
