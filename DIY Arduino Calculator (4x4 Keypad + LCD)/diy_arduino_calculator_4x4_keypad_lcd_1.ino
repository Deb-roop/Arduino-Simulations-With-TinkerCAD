// Include required libraries
#include <Keypad.h>          // Library to manage the 4x4 matrix keypad
#include <LiquidCrystal.h>   // Library to control the 16x2 LCD display

// Initialize the LCD with pins: rs, en, d4, d5, d6, d7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

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

// Create the keypad object using the defined layout and pin connections
Keypad customkeypad = Keypad(makeKeymap(customkeys), rowPins, colPins, ROWS, COLS);

// Define variables used for calculator operations
String input = "";      // To hold the number being entered as a string
char operation;         // To store the selected operator: +, -, *, or /
float num1, num2;       // To store the two operands
float result;           // To store the result after calculation

// The setup function runs once when the Arduino is powered on or reset
void setup() {
  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Display a welcome message
  lcd.setCursor(0, 0);               // Move cursor to first row, first column
  lcd.print("DIY Calculator");       // Print title

  lcd.setCursor(0, 1);               // Move cursor to second row, first column
  lcd.print("Enter numbers:");       // Instruction for user

  delay(4000);                       // Wait 4 seconds so user can read message

  lcd.clear();                       // Clear screen before starting input
}

// The loop function runs continuously after setup()
void loop() {
  // Read the key that was just pressed on the keypad
  char customkey = customkeypad.getKey();

  // If a key was pressed
  if (customkey) {
    
    // If the key is a number (0–9) or decimal point '.'
    if ((customkey >= '0' && customkey <= '9') || customkey == '.') {
      input += customkey;                 // Append the character to the current input string
      lcd.setCursor(0, 0);                // Set cursor to first row
      lcd.print(input);                   // Display current input
    }

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

    // If the 'C' key is pressed, clear all inputs and the screen
    else if (customkey == 'C') {
      input = "";                         // Clear stored input
      lcd.clear();                        // Clear LCD display
    }
  }
}

