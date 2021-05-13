#include<sensor_sim.h>
//#include<iostream>
//#include<ctime>
//#include<unistd.h>

// function returning random int, used to set sensor value
void SensorSim::update_sensor_value(double new_sensor_value){
    sensor_value = new_sensor_value;
}

