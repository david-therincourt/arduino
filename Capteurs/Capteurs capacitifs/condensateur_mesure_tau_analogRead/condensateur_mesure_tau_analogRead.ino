/*
 * Mesure de constante de temps d un circuit RC
 * R = 10,0 kOhm (1%)  C = 437 nF  => tau =   4 484 µs
 * R = 10,0 kOhm (1%)  C = 704 nF  => tau =   7 180 µs
 * R = 10,0 kOhm (1%)  C = 1,01 µF => tau =  10 316 µs
 * R = 99,2 kOhm (1%)  C = 437 µF  => tau =  43 468 µs
 * R = 99,2 kOhm (1%)  C = 704 µF  => tau =  70 124 µs
 * R = 99,2 kOhm (1%)  C = 1,01 µF => tau = 100 812 µs
 */

#define pinE 8

int N = 0;
unsigned long t0;
unsigned long t1;
unsigned long tau;


void setup() {
  Serial.begin(9600);
  Serial.println("-------");
  pinMode(pinE,OUTPUT);      // Broche digitale en sortie

  // DECHARGE COMPLETE
  digitalWrite(pinE,LOW);    // Décharge condensateur avant mesure
  delay(1000);               // pendant 1 s
  int Nmin = analogRead(A0);
  

  // DEBUT CHARGE
  digitalWrite(pinE,HIGH);   // Début charge condensateur
  t0 = micros();             // Mesure instant initial

  while (N<646) {            // Boucle tant que tension inférieure à seuil (0,632*1023=646)
    N = analogRead(A0);      // Lecture tension condensateur
  }
  t1 = micros();             // Mesure instant où seuil atteint
  tau = t1 - t0;             // Calcul de tau
 
  // FIN CAHRGE COMPLETE
  delay(1000);
  int Nmax = analogRead(A0);

  // AFFICHAGE
  Serial.print("Nmin = ");
  Serial.println(Nmin);
  Serial.print("Nmax = ");
  Serial.println(Nmax);
  Serial.print("tau = ");
  Serial.print(tau);          // Début affichage
  Serial.println(" µs");
}

void loop() {
  // Boucle sans fin pas utilisée ici !
}
