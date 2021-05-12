#pragma once
#include<actuator.h>

class Dehumidifier : public Actuator
{
private:

    sf::RectangleShape actuator;

    void draw_actuator() override;
    void update_actuator(int regulator_state) override;
public:
    Dehumidifier() : Actuator(-2){};
};