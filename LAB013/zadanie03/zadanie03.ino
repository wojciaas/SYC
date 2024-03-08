#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() == 0){}
  lcd.clear();
  String dane = Serial.readString();
  lcd.print(dane);
  for(int i = 0; i < dane.length(); i++) {
    Serial.print((int)dane.charAt(i));
    Serial.print(" ");
  }
  Serial.println();
}
