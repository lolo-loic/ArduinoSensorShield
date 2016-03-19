#include "TransmissionBroker.h"

TransmissionBroker::TransmissionBroker()
{  
}

TransmissionBroker::TransmissionBroker(RGBTools& RGB, SensorDriver& sensors, MachineState& state)
                    :transmission_number(0),
                    rgb (&RGB),
                    state (&state),
                    sensors (&sensors)
                    
{
//  rgb = &RGB; 
}

String TransmissionBroker::BuildTransmission()
{
  String JSON_string = ""; // RESET
 
  //TRANSMISSION
  JSON_string += "{\"transmission\":" ;
  JSON_string += String(transmission_number++);
  
  //STATE
  JSON_string += ",\"state\":";
  JSON_string += "[{\"machine\":";
  JSON_string += String(state->getMachineState());

  // Removed LED state indications @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  
  if(state->getMachineState() == 1)
  {
    //SENSORS
    JSON_string += ",\"sensors\":[";
    for(int i = 0; i < 6; i++)
    {
      JSON_string += "{\"sensor\":\"";
      JSON_string += i;
      JSON_string += "\",\"value\":";
      JSON_string += sensors->readSensorValue(i);
      
      // removed sensor state (since now we only have one state for all sensors @@@@@@@@@@@@@@@@@@@@@@@@@@@
      
      if(i < 5)
      {
        JSON_string += ",";
      }
    }
    JSON_string += "]";
  }
  
  
  //ENDING
  JSON_string += "}";
  
  return JSON_string;
}

