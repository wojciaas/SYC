#include <LiquidCrystal.h>
const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
volatile int counter = 0;
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
  Serial.begin(9600);
}

void loop() {
  lcd.print(counter);
  digitalWrite(ledPin, state);
  delay(100);
  lcd.clear();
}

void blink() {
  state = !state;
  counter++;
}