// TP - CNA - MCP4725
// David THERINCOURT 2023
// Installer la librarie "MCP4725" par Rob Tiliaart
// ATTENTION : Sélectionner "Pas de fin de ligne" dans le monitor série !!!

#include "Wire.h"
#include "MCP4725.h"

MCP4725 MCP(0x60);  //  0x60 or 0x61

void setup()
{
	MCP.begin();          // Initialisation du MCP4725
}

void loop()
{
	MCP.setValue(0);                            // Ecriture de la valeur numérique sur le MCP4725
  delay(100);
  MCP.setValue(1000);                            // Ecriture de la valeur numérique sur le MCP4725
  delay(100);
}



