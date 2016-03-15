#include "SensorDriver.h"

SensorDriver::SensorDriver(){
}

void SensorDriver::setSensorState(bool value){
   state = value;
   if(state == 0){
    digitalWrite(4, LOW); // Pin 4 = transistor
    Serial.println("Sensor State = LOW");  
   }
   else {
    digitalWrite(4, HIGH);
    Serial.println("Sensor State = HIGH"); 
   }
}

void SensorDriver::toggleSensorState(){
  state != state;
  if(state == 0){
    digitalWrite(4, LOW);
    Serial.println("Sensor State = LOW"); 
   }
   else {
    digitalWrite(4, HIGH);
    Serial.println("Sensor State = HIGH"); 
   }
}

bool SensorDriver::getSensorState(){
  return state;
}

int SensorDriver::readSensorValue(int x){
  const int sensors[] = {A0, A1, A2, A3, A4, A5};
  return analogRead(sensors[x]); 
}
