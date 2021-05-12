#pragma once
#include<actuator.h>

class Heater : public Actuator
{
private:
    void update_actuator(int regulator_state) override;
public:
    Heater(std::vector<float> greenhouse_info, int section, int actuator_number) : Actuator(2, greenhouse_info, section, actuator_number){};
    void draw_actuator(sf::RenderWindow& window) override;
};


