// LCD Keypad Shield

#include <LiquidCrystal.h>

// Création de l'objet lcd (avec les différents ports numériques qu'il utilise)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Variables
int lcd_key     = 0;
int adc_key_in  = 0;

// Constantes
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

#define IN1 12
#define IN2 13
#define PWM 11
#define SPEED_LOW 50


void setup()
{
 lcd.begin(16, 2);              // Démarrage de l'écran
 lcd.setCursor(0,0);            // Positionnement du curseur au début
 lcd.print("Arduino:essentiel"); // Message
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(PWM, OUTPUT);
}
 
void loop()
{
 lcd.setCursor(0,1);            // Positionnement du curseur début de ligne 1
 lcd_key = read_LCD_buttons();  // Lecture des touches

 switch (lcd_key)               // Action en cas de touche pressée
 {
   case btnRIGHT:
     {
     lcd.print("DROITE");
     avancer();
     break;
     }
   case btnLEFT:
     {
     lcd.print("GAUCHE");
     reculer();
     break;
     }
   case btnUP:
     {
     lcd.print("Mesure");
     mesure();
     break;
     }
   case btnDOWN:
     {
     lcd.print("Stop   ");
     stop();
     break;
     }
   case btnSELECT:
     {
     lcd.print("SELECT");
     break;
     }
     case btnNONE:
     {
     lcd.print("      ");
     break;
     }
 }
}

// Fonction de lecture des touches
int read_LCD_buttons()
{
  adc_key_in = analogRead(0);   // Lecture du port analogique
  // Les valeurs qui suivent doivent être adaptées au shield
  if (adc_key_in > 1000) return btnNONE;   // En principe 1023 quand aucune touche n'est pressée
  if (adc_key_in < 50)   return btnRIGHT;     // 0
  if (adc_key_in < 250)  return btnUP;        // 99
  if (adc_key_in < 450)  return btnDOWN;      // 255
  if (adc_key_in < 650)  return btnLEFT;      // 409
  if (adc_key_in < 880
  )  return btnSELECT;    // 640

  return btnNONE;
}

// Fonction avancer
void avancer()
{
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  rampe_up(1);
  delay(100);
  rampe_down(1);
  delay(100);
  stop();

}

// Fonction reculer
void reculer()
{
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  rampe_up(1);
  delay(100);
  rampe_down(1);
  delay(100);
  stop();
}

// Fonction mesure
void mesure()
{
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  rampe_up(100);
  delay(1000);
  rampe_down(100);
  delay(5000);
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  rampe_up(100);
  delay(1000);
  rampe_down(100);
  delay(100);
  stop();
  
}

// Fonction Stop
void stop()
{
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
}

// Fonction rampe_up
void rampe_up(int dt)
{
  for (int i = 1; i <= 5; i++) {
    analogWrite(PWM, 10*i);
    delay(dt);
  }
}

// Fonction rampe_down
void rampe_down(int dt)
{
  for (int i = 5; i >= 0; i--) {
    analogWrite(PWM, 10*i);
    delay(dt);
  }
}
