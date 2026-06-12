/* Capteur capacitif tactile
 * R = 1M    C = 1nF  + plaque epoxy cuivrée 30cm x 10cm
 * David THERINCOURT - 2025 
 */

int pinD3  = 3; // Broche D3 pour la charge
int pinD2  = 2; // Broche D2 pour la lecture de la tension du condensateur
int pinLed = 8; // Broche LED
int etat;       // Etat de D3 

void setup() {
  Serial.begin(9600);          // Initialisation du port série
  pinMode(pinD3, OUTPUT);      // D2 en sortie (charge condensateur)
  pinMode(pinD2, INPUT);       // D3 en entrée (lecture tension condensateur)
  pinMode(pinLed, OUTPUT);     // LED sur broche 8
}

void loop() {
  // CHARGE DU CONDENSATEUR/home/david/PRO/PRAF_2025/Sphinx/physique-microcontroleurs-2025-2/files/condensateur_mesure_tau/condensateur_mesure_tau_analogRead/condensateur_mesure_tau_analogRead.ino
  digitalWrite(pinD3, HIGH);   // D3 à 5V 
  delayMicroseconds(800);      // Temporisation en µs 
  etat = digitalRead(pinD2);   // Lecture de l'état logique de D2
  Serial.println(etat);      // Affichage de l'état logique de D2
  digitalWrite(pinLed, etat);

  // DECHARGE TOTALE
  digitalWrite(pinD3, 0);      // D3 à 0V
  delay(1000);                 // Temporisation de 1s
}
