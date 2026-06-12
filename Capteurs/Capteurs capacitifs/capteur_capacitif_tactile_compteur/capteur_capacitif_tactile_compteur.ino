/* Capteur capacitif tactile
 * Mesure de l'instant du basculement de D2
 * David THERINCOURT - 2025 
 */
int pinD2 = 2;
int pinD3 = 3;
int duree = 500;
int etatD2;

void setup() {
  Serial.begin(9600);          // Initialisation du port série
  pinMode(pinD3, OUTPUT);      // Pin D3 en sortie (charge condensateur)
  pinMode(pinD2, INPUT);       // Pin D2 en entrée (lecture tension condensateur)
}

void loop() {
  duree = duree + 10;
  
  // DEBUT CHARGE
  digitalWrite(pinD3, HIGH);   // D3 à 5V -> Charge
  delayMicroseconds(duree);    // Temporisation
  etatD2 = digitalRead(pinD2); // Lecture sur D2

  // AFFICHAGE
  Serial.print("durée = ");
  Serial.print(duree);
  Serial.print(" µs    D2 = ");
  Serial.println(etatD2);

  // DEBUT DECHARGE COMPLETE
  digitalWrite(pinD3, LOW);    // D3 à 0V -> Décharge
  delay(100);                 // Temporisation pour décharge complète
}
