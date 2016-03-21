#ifndef TransmissionBroker_h
#define TransmissionBroker_h

#include "Arduino.h"
#include "SensorDriver.h"
#include "MachineState.h"

class TransmissionBroker
{
  public:
    TransmissionBroker();
    TransmissionBroker(SensorDriver &, MachineState &);
    
    String BuildTransmission();
    void ReadTransmission();

    int transmission_number;
    
    SensorDriver *sensors;
    MachineState *state;
  
};
#endif


