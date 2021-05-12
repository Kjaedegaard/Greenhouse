#pragma once

#include<vector>

class Condition{
private:
    double condition_value;
    int condition_state;
    void update_random();
    double change_speed;
    std::vector<double> actuator_informations;
    void update_condition();
    void update_info_from_actuator(std::vector<int> actuator_info);

public:
    Condition(double start_value, double change_factor);
    double get_condition_value(){return condition_value;};
    void update(std::vector<double> actuator_info);
};

