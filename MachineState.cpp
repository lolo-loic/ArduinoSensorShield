#include "MachineState.h"

MachineState::MachineState(){                     
}

MachineState::MachineState(RGBTools& RGB, SensorDriver& sensors)
              :machine_state(0),
               max_machine_state(1),
               rgb (&RGB),
               sensors (&sensors) { 
}

void MachineState::set(int i){
  machine_state = i;
  switch(machine_state) {
    case 0:
      sensors->setSensorState(0);
      rgb->setColor(0,100,0);
    break;
    case 1:
      sensors->setSensorState(1);
      rgb->setColor(0,0,100);
    break;
  }
}

void MachineState::next(){
  if(machine_state == max_machine_state) {
    machine_state = 0;
  }
  else {
    machine_state += 1; // DO NOT PUT machine_state++ lost a lot of time because it doesn't work
  }
  this->set(machine_state);
}

int MachineState::getMachineState(){
  return machine_state;
}

