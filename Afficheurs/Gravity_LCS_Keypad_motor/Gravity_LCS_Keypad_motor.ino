#include <LiquidCrystal.h>

// Brochage DFR0009
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Seuils ADC — valeurs v1.1
#define BTN_RIGHT  0
#define BTN_UP     1
#define BTN_DOWN   2
#define BTN_LEFT   3
#define BTN_SELECT 4
#define BTN_NONE   5

#define IN1 1
#define IN2 2
#define PWM 3

void stop() {
  lcd.clear();
  lcd.print("Commande moteur");
  lcd.setCursor(0, 1);
  lcd.print("STOP");
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
}

void right() {
  lcd.clear();
  lcd.print("Commande moteur");
  lcd.setCursor(0, 1);
  lcd.print("RIGHT");
  analogWrite(PWM, 50);
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  delay(1000);
}

void left() {
  lcd.clear();
  lcd.print("Commande moteur");
  lcd.setCursor(0, 1);
  lcd.print("LEFT");
  analogWrite(PWM, 50);
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  delay(1000);
}

void select() {
  lcd.clear();
  lcd.print("Commande moteur");
  lcd.setCursor(0, 1);
  lcd.print("Mesure ...");
  analogWrite(PWM, 150);
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  delay(2000);
}

void readButton() {
  int val = analogRead(A0);
  if (val < 50)   {right(); return;}  // BTN_RIGHT;
  if (val < 250)  return ; // BTN_UP;
  if (val < 450)  return ; // BTN_DOWN;
  if (val < 650)  {left(); return;}   // BTN_LEFT;
  if (val < 850)  {select(); return;} // BTN_SELECT;
  stop();
}

void setup() {
  lcd.begin(16, 2);
  lcd.print("Commande moteur");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
}

void loop() {
  readButton();
  delay(100);
}