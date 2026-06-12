// TP - CNA - MCP4725
// David THERINCOURT 2023
// Installer la librarie "MCP4725" par Rob Tiliaart
// ATTENTION : Sélectionner "Pas de fin de ligne" dans le monitor série !!!

#include "Wire.h"
#include "MCP4725.h"

MCP4725 MCP(0x60);  //  0x60 or 0x61

void setup()
{
  Serial.begin(9600);   // Initialisation du port série
  MCP.begin();          // Initialisation du MCP4725
}

void loop()
{
  Serial.print("Entrer une valeur de N : ");  // Indication à l'utilisateur
  while (Serial.available()==0){}             // Attente d'un message (Cocher "Pas de fin de ligne")
  int N = Serial.parseInt();                  // Extraction de la valeur numérique (entier)
  Serial.println(N);                          // Affichage
  MCP.setValue(N);                            // Ecriture de la valeur numérique sur le MCP4725
}
