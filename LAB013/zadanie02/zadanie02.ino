#include <LiquidCrystal.h>

volatile float duty_cycle = 500;
const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(A0,INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), increase, FALLING);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, state);
  delay(duty_cycle);
  state = !state;
  if(Serial.available() != 0) {
    reset();
    Serial.readString();
  }
}

void increase() {
  duty_cycle *= 0.9;
}

void reset() {
  duty_cycle = 500;
}