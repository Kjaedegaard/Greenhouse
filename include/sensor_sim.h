#pragma once
#include<conditions.h>
// sensorsim class simulates the sensor in the greenhouse, it contains a sensorvalue which is updated based on the regulator states
// the sensorsim class therefor also acts as the actuator in this simulation
class SensorSim{
private:
    double sensor_value;
public:
    void update_sensor_value(double new_sensor_value);
    double get_sensor_value(){return sensor_value;};
};
