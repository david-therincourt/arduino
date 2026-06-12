/*
 * R = 99.4k  C = 10,2 nF  => tau = 1012 µs
 * R = 99.4k  C = 4,94 nF  => tau = 496 µs
 * R = 10k    jusqu'à 1000 nF   (tau = 10 ms max)
 * R = 100k   jusqu'à 100 nF    (tau = 10 ms max)
 * R = 1M     jusqu'à 10 nF     (tau = 10 ms max)
*/

#include "analogComp.h"

unsigned long t0;  // 32 bits
unsigned long t1;
unsigned long tau;
float C;
float R = 1.0E6;

void setup() {
  Serial.begin(9600);
  Serial.println("-----------");

  analogComparator.setOn(AIN0, AIN1); //we instruct the lib to use voltages on the pins
  analogComparator.enableInterrupt(changeStatus, RISING);

  pinMode(8,OUTPUT);      // Broche digitale en sortie

  // DECHARGE COMPLETE
  digitalWrite(8,LOW);    // Décharge condensateur avant mesure
  delay(1000);               // pendant 1 s


  // DEBUT CHARGE
  digitalWrite(8,HIGH);   // Début charge condensateur
  t0 = micros();             // Mesure instant initial

}

void loop() {
  
}

void changeStatus() {
  analogComparator.disableInterrupt();
  t1 = micros();             // Mesure instant où seuil atteint
  tau = t1 - t0;              // Calcul de tau
  C = tau/R * 1E4;
  Serial.print("tau = ");
  Serial.print(tau);          // Début affichage
  Serial.print(" µs \t C = ");
  Serial.print(C);          // Début affichage
  Serial.println(" nF");
}