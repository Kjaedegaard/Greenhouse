#pragma once
#include<actuator.h>

class Cooler : public Actuator
{
private:
    //void draw_actuator(sf::RenderWindow& window) override;
    void update_actuator(int regulator_state) override;
public:
    Cooler() : Actuator(-0.6){};
};
