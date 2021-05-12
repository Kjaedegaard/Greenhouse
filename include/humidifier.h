#pragma once
#include<actuator.h>

class Humidifier : public Actuator
{
private:
    void update_actuator(int regulator_state) override;
public:
    Humidifier(std::vector<float> greenhouse_info, int section, int actuator_number) : Actuator(5, greenhouse_info, section, actuator_number){};
    void draw_actuator(sf::RenderWindow& window) override;
};