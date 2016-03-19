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

RGBTools rgb(9,10,11);       // set RGB Pins
int button = 2;              // set interrupt pin

MachineState state;          // defined here to share between main() and interact()
SensorDriver sensors;

//---------------------------SETUP------------------------------
void setup(){
  Serial.begin(9600);
  Serial.print("SETUP... ");
  
  pinMode(A0, INPUT);       // sensors inputs
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  
  pinMode(button, OUTPUT);
  digitalWrite(button, HIGH); 
  attachInterrupt(0, interaction, FALLING); // 0 = pin2 -> interrupt

  delay(1000);
  
  rgb.setColor(200,0,0); // hardware indication 
  delay(1000);
  Serial.println("Finished setup");
  rgb.setColor(50,50,50); 
}


//-------------------------MAIN LOOP------------------------------
void loop(){
 TransmissionBroker broker(rgb, sensors, state);
  for(int i =0; i < 9000 ; i++) {
    
    Serial.println(broker.BuildTransmission());
    delay(1000);
  }
  
//  for (int i = 0; i < 6; i++) {
//   Serial.print("   A");
//   Serial.print(i);
//   Serial.print(": ");
//   Serial.print(sensors.readSensorValue(i));
//   delay(10);
//  }
//  Serial.println(""); 
//  delay(500); 
  
}

// -----------------------Interrupt-----------------------------
void interaction() {
    Serial.print("State change, new MachineState: ");
    state.next();
    Serial.println(state.getMachineState());

    if(state.getMachineState()) {
        rgb.setColor(0,100,0);
        sensors.setSensorState(true);
      }
      else {
        sensors.setSensorState(false);
        rgb.setColor(0,0,100);
      }
}
