#pragma once
#include<actuator.h>

class Heater : public Actuator
{
private:
    //void draw_actuator(sf::RenderWindow& window) override;
    void update_actuator(int regulator_state) override;
public:
    Heater() : Actuator(2){};
    
};


