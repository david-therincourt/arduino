/* Capteur capacitif (touch)
 * David THERINCOURT - 2025 
 */

int duree;
int etat;

void setup() {
  Serial.begin(9600);            // Initialisation du port série
  pinMode(3, OUTPUT);        // D3 en sortie (charge condensateur)
  pinMode(2, INPUT);         // D2 en entrée (lecture tension condensateur)
  Serial.print("Start time (µs) = ");
  while (Serial.available()==0){}                      // Attente d'un message (Cocher "Pas de fin de ligne")
  duree = Serial.parseInt();                           // Extraction de la valeur numéri
  Serial.println(duree);
}

void loop() {
  

  // DEBUT CHARGE
  digitalWrite(3, 1);    // Début charge du condensateur
  delayMicroseconds(duree);
  etat = digitalRead(2);
  Serial.print("t_m = ");
  Serial.print(duree);
  Serial.print(" µs \t D2 = ");
  Serial.println(etat);

  duree = duree + 10;

  // DEBUT DECHARGE COMPLETE
  digitalWrite(3, 0);    // Début décharge du condensateur
  delay(1000);                    // Temporisation pour charge complète
}


