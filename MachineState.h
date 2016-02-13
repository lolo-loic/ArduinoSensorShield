#ifndef MachineState_h
#define MachineState_h

#include "Arduino.h"

class MachineState
{
  public:
    MachineState();
    void set(int);
    void next();                                  // Interrupt
    int getMachineState();
    
    int machine_state;                            // circular integer for state
    int max_machine_state;                        
};

#endif
