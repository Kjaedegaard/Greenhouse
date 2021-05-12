#include<humidifier.h>
#include<dehumidifier.h>
#include<heater.h>
#include<cooler.h>
#include<actuator.h>

void Humidifier::update_actuator(int regulator_state){
    if(regulator_state == 2){
        actuator_state = true;
    }
    else{
        actuator_state = false;
    }

}


void Humidifier::draw_actuator(){
    actuator.setPosition(sf::Vector2f{20,20});
    actuator.setSize(sf::Vector2f{30,10});
    actuator.setFillColor(sf::Color::Red);
}

void Heater::draw_actuator(){
    actuator.setPosition(sf::Vector2f{20,20});
    actuator.setSize(sf::Vector2f{30,10});
    actuator.setFillColor(sf::Color::Red);
}

void Cooler::draw_actuator(){
    actuator.setPosition(sf::Vector2f{20,20});
    actuator.setSize(sf::Vector2f{30,10});
    actuator.setFillColor(sf::Color::Red);
}

void Dehumidifier::draw_actuator(){
    actuator.setPosition(sf::Vector2f{20,20});
    actuator.setSize(sf::Vector2f{30,10});
    actuator.setFillColor(sf::Color::Red);
}

void Dehumidifier::update_actuator(int regulator_state){
    if(regulator_state == 3){
        actuator_state = true;
    }
    else{
        actuator_state = false;
    }

}

void Heater::update_actuator(int regulator_state){
    if(regulator_state == 2){
        actuator_state = true;
    }
    else{
        actuator_state = false;
    }

}

void Cooler::update_actuator(int regulator_state){
    if(regulator_state == 3){
        actuator_state = true;
    }
    else{
        actuator_state = false;
    }

}