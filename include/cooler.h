#pragma once
#include<actuator.h>

class Cooler : public Actuator
{
private:
    void update_actuator(int regulator_state) override;
public:
    Cooler(std::vector<float> greenhouse_info, int section, int actuator_number) : Actuator(-1, greenhouse_info, section, actuator_number){};
    void draw_actuator(sf::RenderWindow& window) override;
};
