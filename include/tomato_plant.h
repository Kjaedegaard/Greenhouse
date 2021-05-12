#pragma once
#include<plant.h>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include<tomato.h>
#include<tomato_branch.h>

// tomato_plant class inherrits the plant class. its main purpose is to create and update the main part of the tomato plant
// ect. the body

class Tomato_plant : public Plant
{
private:
    int number_tomatoes;
    int number_branches;
    sf::RectangleShape plant_base;
    std::vector<Branch> branches;
    void grow() override;
    void create_branch(int side);
    
public:
    Tomato_plant(std::vector<double> hum_conditions, std::vector<double> temp_conditions, std::vector<float> coordinates):Plant(hum_conditions, temp_conditions, coordinates){};
    void plant_tomato();
    void update_tomato(sf::RenderWindow& window);

};

