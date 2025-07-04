#include <Keypad.h>

#define red 10
#define green 11
#define buzz 12

const byte ROW = 4;
const byte COL = 4;

// Define the keymap
char numpad [ROW][COL] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// define row and col pins
byte rowPin[ROW] = { 9, 8, 7,6};
byte colPin[COL] = {5, 4, 3,2};

// Define the password
const String password = "6556";
String vstup = "";

// Create the Keypad
Keypad cKeypad = Keypad(makeKeymap(numpad), rowPin, colPin, ROW, COL);

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzz, OUTPUT);
  digitalWrite(red,HIGH);
  Serial.begin(9600);
  Serial.print("Enter Passcode: ");
}

void loop()
{
  char cKey = cKeypad.getKey();
  
  if(cKey){
    if(vstup.length() < 4) {
      Serial.print("*");
      vstup +=cKey;
    }
  }
  if (vstup.length() == 4) {
    delay(1500);
    if(password == vstup){
      Serial.println("\nEnter");
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      tone(buzz, 500);
      delay(100);
      noTone(buzz);
    } else {
      Serial.println("\nWrong Passcode");
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      tone(buzz, 1000);
      delay(800);
      noTone(buzz);
    }
    delay(1500);

    vstup = "";
    Serial.println("Enter Passcode:");
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }
}