//   |-----|-----------------------|---------------------------------------------------------------
//   | Pin#| Use                   |  Notes
//   |-----|-----------------------|---------------------------------------------------------------
//   | 0   |                    
//   | 1   |                    
//   | 2   |  Interrupt                           
//   | 3   |     
//   | 4   |  Transistor
//   | 5   | 
//   | 6   |
//   | 7   | 
//   | 8   |
//   | 9   |  Red RGB pin
//   | 10  |  Green RGB pin
//   | 11  |  Blue RGB pin
//   | 12  |                      
//   | 13  |                      
//   |-----|------------------------|----------------------------------------------------------------
//   | A0  |  Sensor 1                can be anything : photosensor, temperaute, humidity, pot , force, sound (piezo)
//   | A1  |  Sensor 2
//   | A2  |  Sensor 3
//   | A3  |  Sensor 4
//   | A4  |  Sensor 5
//   | A5  |  Sensor 6
//   |-----|------------------------|----------------------------------------------------------------


//-------------------------Includes-----------------------------
#include "Arduino.h"
#include "RGBTools.h"
#include "SensorDriver.h"
#include "MachineState.h"
#include "TransmissionBroker.h"

int button = 2;              // set interrupt pin

RGBTools rgb(9,10,11);       // set RGB Pins
SensorDriver sensors;        
MachineState state (rgb, sensors);   
TransmissionBroker broker(sensors, state);

//---------------------------SETUP------------------------------
void setup(){
  rgb.setColor(200,0,0);     // hardware indication 
  Serial.begin(9600);
  Serial.print("Setup... ");
  
  pinMode(A0, INPUT);        // sensors inputs
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  
  pinMode(button, OUTPUT);
  digitalWrite(button, HIGH); 
  attachInterrupt(0, interaction, FALLING); // 0 = pin2 -> interrupt
  
  delay(1000);
  Serial.println("Finished setup");
  rgb.setColor(50,50,50); 
}

//-------------------------MAIN LOOP------------------------------
void loop(){
  broker.ReadTransmission();
  Serial.println(broker.BuildTransmission());
  delay(100);
}

// -----------------------Interrupt-----------------------------
void interaction() {
  state.next();
}
