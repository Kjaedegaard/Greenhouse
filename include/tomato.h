#pragma once
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

// Tomato class is used by the tomato branch class to create tomatoes, a tomato consists of an circle shape which is
// manipulated by the class functions

class Tomato
{
private:
    sf::CircleShape tomato_obj;
    float tomato_size = 1;
    std::vector<float> tomato_position;
    
public:
    Tomato(std::vector<float> coordinates);
    void grow();
    void update(sf::RenderWindow& window);
    void harvest();
};

