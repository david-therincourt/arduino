//
//    FILE: MCP4922_standalone.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: faster no checking MCP4922 specific code
//     URL: https://github.com/RobTillaart/MCP_DAC


#include "SPI.h"

#define MCP4922_CS_PIN    10

uint32_t start, stop;


void setup()
{
  
  pinMode(MCP4922_CS_PIN, OUTPUT);
  digitalWrite(MCP4922_CS_PIN, HIGH);
  SPI.begin();

  Serial.begin(9600);
  Serial.println("Régler le min à 0V et");
}


void mcp4922(uint16_t value, uint8_t channel)  //  channel = 0, 1
{
  uint16_t data = 0x3000 | value;
  if (channel == 1) data |= 0x8000;
  digitalWrite(MCP4922_CS_PIN, LOW);
  SPI.beginTransaction(SPISettings(16000000, MSBFIRST, SPI_MODE0));
  SPI.transfer((uint8_t)(data >> 8));
  SPI.transfer((uint8_t)(data & 0xFF));
  SPI.endTransaction();
  digitalWrite(MCP4922_CS_PIN, HIGH);
}



void loop()
{
    mcp4922(0, 0);         // 2048 - 3*600 = 248
    delay(4);
    mcp4922(2048, 0);         // 2048 - 3*600 = 248
    delay(2);
    mcp4922(4095, 0);         // 2048 - 3*600 = 248
    delay(4);
}


//  -- END OF FILE --
