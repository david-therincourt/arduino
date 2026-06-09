/*
 * HX711_ADC — Arduino UNO R3
 * Lecture valeur brute ADC, moyenne sur 128 échantillons, sans tare
 * Toutes les secondes
 */

#include <HX711_ADC.h>

const int PIN_DOUT = 5;
const int PIN_SCK  = 4;

HX711_ADC loadCell(PIN_DOUT, PIN_SCK);

unsigned long dernierAffichage = 0;
unsigned long offset = 8430820;
unsigned long sensibilite = 587.0;
unsigned long mesure;
float masse;

void setup() {
  Serial.begin(115200);

  loadCell.begin();
  loadCell.start(2000, false);   // stabilisation 2s, pas de tare auto

  loadCell.setCalFactor(1.0);    // pas d'étalonnage : getData() retourne des LSB
  loadCell.setTareOffset(offset);     // offset zéro : aucune soustraction
  loadCell.setSamplesInUse(128); // moyenne glissante sur 128 échantillons
  Serial.println("-----");
}

void loop() {
  loadCell.update();

  if (millis() - dernierAffichage >= 1000) {
    dernierAffichage = millis();
    mesure = loadCell.getData(); // valeur brute en LSB
    Serial.println(mesure);
    masse = mesure/sensibilite;
    Serial.print(masse); Serial.println(" g");
  }
}
