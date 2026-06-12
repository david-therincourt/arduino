/* Capteur capacitif tactile
 * Mesure de la durée du basculement de l'entrée digitale D2 (seuil de 2,5V)
 * David THERINCOURT - 2025 
 */

int pinD3 = 3;  // Broche D3 
int pinD2 = 2;  // Broche D2 

unsigned long t_init;            // Instant initial
unsigned long t_rise;            // Instant de basculement

void setup() {
  Serial.begin(9600);            // Initialisation du port série
  pinMode(pinD3, OUTPUT);        // broche D3 en sortie (charge condensateur)
  pinMode(pinD2, INPUT);         // broche D2 en entrée (lecture tension condensateur)
  attachInterrupt(digitalPinToInterrupt(pinD2),  detection, RISING); // Parmetrage interruption
}

void loop() {
  // DEBUT CHARGE COMPLETE
  digitalWrite(pinD3, 1);        // D3 à 5V
  t_init = micros();             // Mesure instant début
  delay(500);                    // Temporisation pour charge complète

  // DEBUT DECHAGRE COMPLETE
  digitalWrite(pinD3, 0);        // Début décharge du condensateur
  delay(500);                    // Temporisation pour charge complète
}

void detection() {
  t_rise = micros();             // Mesure instant du basculement de 0 à 5V
  Serial.print(t_rise - t_init); // Affichage durée de basculement
  Serial.println(" µs");         // Affichage unité + saut de ligne
}
