#pragma once
#include<actuator.h>

class Heater : public Actuator
{
private:

    sf::RectangleShape actuator;

    void draw_actuator() override;
    void update_actuator(int regulator_state) override;
public:
    Heater() : Actuator(2){};
    
};


