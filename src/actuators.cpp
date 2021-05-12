#include<humidifier.h>
#include<dehumidifier.h>
#include<heater.h>
#include<cooler.h>
#include<actuator.h>
#include<iostream>

void Humidifier::update_actuator(int regulator_state){
    if(regulator_state == 3){
        actuator_state = true;
        std::cout << "humidifier on \n";
    }
    else{
        actuator_state = false;
    }
}

void Humidifier::draw_actuator(sf::RenderWindow& window){
    if(actuator_state){
        actuator.setFillColor(sf::Color::Green);
    }
    else{
        actuator.setFillColor(sf::Color::Cyan);
    }
    window.draw(actuator);
}


void Dehumidifier::update_actuator(int regulator_state){
    if(regulator_state == 2){
        actuator_state = true;
        std::cout << "Dehumidifier on \n";
    }
    else{
        actuator_state = false;
    }

}

void Dehumidifier::draw_actuator(sf::RenderWindow& window){
    if(actuator_state){
        actuator.setFillColor(sf::Color::Green);
    }

    else{
        actuator.setFillColor(sf::Color::Cyan);
    }
    window.draw(actuator);
}

void Heater::update_actuator(int regulator_state){
    if(regulator_state == 3){
        actuator_state = true;
        std::cout << "Heater on \n";
    }
    else{
        actuator_state = false;
    }
}

void Heater::draw_actuator(sf::RenderWindow& window){
    if(actuator_state){
        actuator.setFillColor(sf::Color::Red);
    }
    else{
        actuator.setFillColor(sf::Color::Cyan);
    }
    window.draw(actuator);

}

void Cooler::update_actuator(int regulator_state){
    if(regulator_state == 2){
        actuator_state = true;
        std::cout << "Cooler on \n";
    }
    else{
        actuator_state = false;
    }
}

void Cooler::draw_actuator(sf::RenderWindow& window){
    if(actuator_state){
        actuator.setFillColor(sf::Color::Blue);
    }

    else{
        actuator.setFillColor(sf::Color::Cyan);
    }
    window.draw(actuator);

}