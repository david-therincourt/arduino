/*!
 * @file DFRobotOutputVoltage.ino
 * @brief Output a constant voltage value and print through the serial port.
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [TangJie]](jie.tang@dfrobot.com)
 * @version  V1.0.0
 * @date  2018-01-15
 * @url https://github.com/DFRobot/DFRobot_MCP4725
 */
#include "Wire.h"
#include "DFRobot_MCP4725.h"

DFRobot_MCP4725 DAC;

#define Vref 5.00

float tension ;
float courant ;


void setup(void) {
  
  Serial.begin(9600);
  DAC.init(0x60, Vref*1000);

}

void loop(void) {

  Serial.println("E\tU\tI");
  Serial.println("V\tV\tmA");
  for (int e=0; e<5000; e=e+100){
    DAC.outputVoltage(e);
    tension = analogRead(A0)*Vref/1023;
    courant = (analogRead(A1)*Vref/1.023)/120.0;
    Serial.print(e/1000.0,3);
    Serial.print("\t");
    Serial.print(tension,3);
    Serial.print("\t");
    Serial.println(courant,5);
    delay(500);
  }

  while (1==1) {}
  

  
}
