#ifndef SensorDriver_h
#define SensorDriver_h

#include "Arduino.h"

class SensorDriver
{
  public:
    SensorDriver();
    void setSensorState(bool);
    void toggleSensorState(); 
    bool getSensorState();
    
    int readSensorValue(int);
    
    int sensors[];                     // array of sensor pins
    boolean state;                     // on/off states of sensors
  
};
#endif
