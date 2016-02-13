#include "MachineState.h"

MachineState::MachineState(){                     
    machine_state = 0;
    max_machine_state = 1;
}

void MachineState::set(int i){
  machine_state = i;
}

void MachineState::next(){
  if(machine_state == max_machine_state) {
    machine_state = 0;
  }
  else {
    machine_state = machine_state + 1; // DO NOT PUT machine_state++ lost a lot of time because it doesn't work
  }
}

int MachineState::getMachineState(){
  return machine_state;
}

