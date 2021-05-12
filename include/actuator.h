#pragma once
#include<vector>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Actuator
{
protected:

    sf::RectangleShape actuator;
    bool actuator_state = false;
    int power;
    bool get_state(){return actuator_state;};
    void init_actuator(std::vector<float> greenhouse_info, int section, int actuator_number);
    virtual void update_actuator(int regulator_state) = 0;

public:
    Actuator(double _power, std::vector<float> greenhouse_info, int section, int acutator_number);
    double actuate(int regulator_state);
    virtual void draw_actuator(sf::RenderWindow& window) = 0;
};
