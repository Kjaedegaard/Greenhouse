#pragma once
#include <vector>


// regulator class acts as the brain of the greenhouse, it decides if the actuator should be activated or not based on the
// sensorvalues 
class Regulator{
private:
    int regulator_state = 0;
    std::vector<double> regulator_goal_value; 

public:
    Regulator(std::vector<double> goal_values);
    void getSensorValue();
    void update(double sensor_value);
    int get_state(){return regulator_state;};

};
