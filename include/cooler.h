#pragma once
#include<actuator.h>

class Cooler : public Actuator
{
private:

    sf::RectangleShape actuator;

    void draw_actuator() override;
    void update_actuator(int regulator_state) override;
public:
    Cooler() : Actuator(-0.6){};
};
