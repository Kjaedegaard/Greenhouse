#pragma once
#include<vector>

// parent class fo plant classes, contains contructor, getters, setters and function to calculate the livingconditions.
class Plant
{
protected:
    float height = 2;
    float width = 2;
    double living_conditions = 50;
    std::vector<double> plant_opt_hum_conditions;
    std::vector<double> plant_opt_temp_conditions;
    std::vector<float> plant_position;
    virtual void grow() = 0;

public:
    Plant(std::vector<double> hum_condition, std::vector<double> temp_condtion, std::vector<float> coordinates);
    //double get_height(){return height;};
    //double get_width(){return width;};
    double get_living_conditions(){return living_conditions;};;
    void cal_living_conditions(std::vector<int> regulator_states);
    std::vector<double> get_opt_hum_conditions(){return plant_opt_hum_conditions;};
    std::vector<double> get_opt_temp_conditions(){return plant_opt_temp_conditions;};
};
