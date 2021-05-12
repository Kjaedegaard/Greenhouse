#pragma once
#include<vector>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Actuator
{
protected:
    bool actuator_state = false;
    int power;
    bool get_state(){return actuator_state;};
    virtual void update_actuator(int regulator_state) = 0;
    virtual void draw_actuator() = 0;

public:
    Actuator(double _power);
    double actuate(int regulator_state);
};
