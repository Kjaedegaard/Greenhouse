#include<regulator.h>
#include<iostream>
#include<vector>
#include<algorithm>

// constructor
Regulator::Regulator(std::vector<double> goal_values){
    regulator_goal_value = goal_values;
    //std::sort(regulator_goal_value.begin(),regulator_goal_value.end());
}

// function that takes the sensorvalue from a sensor and compares it to the goalvalues given in the constructor.
// it sest the regulator state to 1,2 or three based on wheter the sensorvalue is high, low or accepteble
void Regulator::update(double sensor_value)
{
    if(sensor_value <= regulator_goal_value[0]){
        regulator_state = 3;
    }
    else if(sensor_value >= regulator_goal_value[1]){
        regulator_state = 2;
    }
    else if (sensor_value > regulator_goal_value[0] and sensor_value < regulator_goal_value[1]){
        regulator_state = 1;
    }
}