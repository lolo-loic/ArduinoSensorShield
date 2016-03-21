#ifndef MachineState_h
#define MachineState_h

#include "Arduino.h"
#include "RGBTools.h"
#include "SensorDriver.h"

class MachineState
{
  public:
    MachineState();
    MachineState(RGBTools &, SensorDriver &);
    
    void set(int);        // Engine Logic in here
    void next();          // does set(machine_state++)                        
    int getMachineState();
    
    int machine_state;                            
    int max_machine_state;         

    RGBTools *rgb;
    SensorDriver *sensors;    
};

#endif
