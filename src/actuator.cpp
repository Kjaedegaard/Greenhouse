#include<actuator.h>

Actuator::Actuator(double _power){
    power = _power;
}

double Actuator::actuate(int regulator_state, sf::RenderWindow& window){
    update_actuator(regulator_state);
    if(actuator_state){
        return power;
    } 

    else{
        return 0;
    }
    draw_actuator(sf::RenderWindow& window);

}