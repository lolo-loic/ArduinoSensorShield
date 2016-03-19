#ifndef TransmissionBroker_h
#define TransmissionBroker_h

#include "Arduino.h"
#include "RGBTools.h"
#include "SensorDriver.h"
#include "MachineState.h"

class TransmissionBroker
{
  public:
    TransmissionBroker();
    TransmissionBroker(RGBTools &, SensorDriver &, MachineState &);
    String BuildTransmission();

    int transmission_number;
    
    RGBTools *rgb;
    SensorDriver *sensors;
    MachineState *state;
  
};
#endif


