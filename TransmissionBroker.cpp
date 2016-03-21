#include "TransmissionBroker.h"

TransmissionBroker::TransmissionBroker()
{  
}

TransmissionBroker::TransmissionBroker(SensorDriver& sensors, MachineState& state)
                    :transmission_number(0),
                    state (&state),
                    sensors (&sensors) {
}

String TransmissionBroker::BuildTransmission()
{
  // Reset
  String JSON_string = ""; 
 
  // Transmission number
  JSON_string += "{t:" ;
  JSON_string += String(transmission_number++);
  
  // Machine state
  JSON_string += ",m:";
  JSON_string += String(state->getMachineState());
  
  if(state->getMachineState() == 1)
  {
    // Sensor values
    JSON_string += ",s:[";
    for(int i = 0; i < 6; i++) 
    {
      JSON_string += sensors->readSensorValue(i);
      if(i < 5)
      {
        JSON_string += ",";
      }
    }
    JSON_string += "]";
  }
  
  // End Transmission
  JSON_string += "}";
  return JSON_string;
}

void TransmissionBroker::ReadTransmission()
{
  if (Serial.available() > 0) 
  {
    String incomingTransmission = Serial.readString(); // read transmission
    
    int x = incomingTransmission[3] - '0';  // get state command
    Serial.println(incomingTransmission);
//    Serial.println(incomingTransmission[0]);
//    Serial.println(incomingTransmission[1]);
    Serial.println(incomingTransmission[3]);
    Serial.println(x);
    state->set(x);                    // set new state
  }
}

