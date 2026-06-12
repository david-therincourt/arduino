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

int readButton() {
  int val = analogRead(A0);
  if (val < 50)   return BTN_RIGHT;
  if (val < 250)  return BTN_UP;
  if (val < 450)  return BTN_DOWN;
  if (val < 650)  return BTN_LEFT;
  if (val < 850)  return BTN_SELECT;
  return BTN_NONE;
}

void setup() {
  lcd.begin(16, 2);
  lcd.print("Appuyez...");
}

void loop() {
  int btn = readButton();

  lcd.setCursor(0, 1);
  switch (btn) {
    case BTN_RIGHT:  lcd.print("RIGHT  "); break;
    case BTN_UP:     lcd.print("UP     "); break;
    case BTN_DOWN:   lcd.print("DOWN   "); break;
    case BTN_LEFT:   lcd.print("LEFT   "); break;
    case BTN_SELECT: lcd.print("SELECT "); break;
    case BTN_NONE:   lcd.print("---    "); break;
  }
  delay(100);
}