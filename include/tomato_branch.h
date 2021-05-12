#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<tomato.h>
#include<iostream>

// the tomato branchs class is used by the tomato plant class to create branches, a brach cosistst of a rectangle
// objecet which is manipulated by the class functions

class Branch
{
private:
    float branch_width = 1;
    float branch_lenght = 1;
    sf::RectangleShape branch;
    int growing_direction;
    std::vector<float> position;
    std::vector<Tomato> tomatoes;
    void set_tomato_pair();
    void grow();

public:
    Branch(int side, std::vector<float> current_pos);
    void update_branch(sf::RenderWindow& window);
};



