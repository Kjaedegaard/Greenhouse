#pragma once
#include<actuator.h>

class Humidifier : public Actuator
{
private:
    //void draw_actuator(sf::RenderWindow& window) override;
    void update_actuator(int regulator_state) override;
public:
    Humidifier() : Actuator(5){};
    
};