// PWM avec saisie du rapport cyclique (entier de 0 à 255) au clavier dans le moniteur série.
// ATTENTION : Sélectionner "Pas de fin de ligne" dans le monitor série !!!
// David THERINCOURT 2025

#define LED 9           // LED connectée à la broche 11

void setup()
{
  Serial.begin(9600);   // Initialisation du port série
  pinMode(LED,OUTPUT);  // Configuration de la broche LED en sortie
}

void loop()
{
  Serial.print("Rapport cyclique entre 0 et 255 : ");  // Indication à l'utilisateur
  while (Serial.available()==0){}                      // Attente d'un message (Cocher "Pas de fin de ligne")
  int N = Serial.parseInt();                           // Extraction de la valeur numérique (entier)
  Serial.println(N);                                   // Affichage de N
  analogWrite(LED, N);                                 // Ecriture sur la sortie PWM
}
