#include<actuator.h>
#include<iostream>

Actuator::Actuator(double _power, std::vector<float> greenhouse_info, int section, int actuator_number){
    power = _power;
    init_actuator(greenhouse_info, section, actuator_number);

}

double Actuator::actuate(int regulator_state){
    update_actuator(regulator_state);
    if(actuator_state){
        return power;
    } 
    else{
        return 0;
    }
}

void Actuator::init_actuator(std::vector<float> greenhouse_info, int section, int actuator_number){
    float actuator_size = ((greenhouse_info[2]-10)/2)/4;
    float x_cord = greenhouse_info[0]+5+(section-1)*greenhouse_info[2]/2+(actuator_number-1)*actuator_size;
    float y_cord = greenhouse_info[1]+5;

    actuator.setPosition(sf::Vector2f{x_cord,y_cord});
    actuator.setSize(sf::Vector2f{actuator_size,30});
    actuator.setFillColor(sf::Color::Cyan);
}