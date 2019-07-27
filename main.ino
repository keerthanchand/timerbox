#include <Servo.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Wire.h>
#include "RTClib.h"

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


RTC_DS3231 rtc;

Servo myservo;  
int start_pnt = 10;
int end_pnt = 100;



const int numOfInputs = 4;
const int inputPins[numOfInputs] = {0, 8, 10, 11};
int inputState[numOfInputs];
int lastInputState[numOfInputs] = {LOW, LOW, LOW, LOW};
bool inputFlags[numOfInputs] = {LOW, LOW, LOW, LOW};
long lastDebounceTime[numOfInputs] = {0, 0, 0, 0};
long debounceDelay = 5;
const int numOfScreens = 7;
int currentScreen = 0;
String screens[numOfScreens][1] = {{"     Date"}, {"     Month"},
  {"      Year"}, {"     Hours"}, {"    Minutes"}, {"   save (Y/N)"}, {"Change Time(Y/N)"}
};
int parameters[numOfScreens];



const int buttonPin = 12;    
int ledState = 0;        
int buttonState;             
int lastButtonState = LOW;   
unsigned long LastDebounceTime = 0; 
unsigned long debounceDelay1 = 50;    

byte smile[8] = { 0b00000, 0b01010, 
                  0b11111, 0b11111, 
                  0b11111, 0b01110, 
                  0b00100, 0b00000 
                 }; 

void setup() {

lcd.createChar(2, smile);
  for (int i = 0; i < numOfInputs; i++) {
    pinMode(inputPins[i], INPUT);
    digitalWrite(inputPins[i], HIGH);
    pinMode(buttonPin, INPUT);
    pinMode(A0, OUTPUT);
    digitalWrite(buttonPin, HIGH);
    int cons = EEPROM.read(2) + 2000;
    parameters[0] = EEPROM.read(0);
    parameters[1] = EEPROM.read(1);
    parameters[2] = 2000 + EEPROM.read(2);
    parameters[3] = EEPROM.read(3);
    parameters[4] = EEPROM.read(4);
    
  } 
     myservo.attach(9);  

  myservo.write(start_pnt);                 

  lcd.begin(16, 2);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
}




void loop() {
int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    LastDebounceTime = millis();
  }
    if ((millis() - LastDebounceTime) > debounceDelay1) {
   
    if (reading != buttonState) {
      buttonState = reading;

     
      if (buttonState == HIGH && ledState == 0) {
        ledState = 1;
      }
      else if (buttonState == HIGH && ledState == 1) {
        ledState = 2;
      }
      else if (buttonState == HIGH && ledState == 2) {
        ledState = 0;
      }
    }
  }
  lastButtonState = reading;


if (ledState ==2){
  homescreen();
}

else if(ledState == 0){
  printScreen();
  setInputFlags();
  resolveInputFlags();
}
if (ledState == 1){
    dateconv();

}

}
