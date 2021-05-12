#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>


// clas contining the element depicting the greenhouse
class Greenhouse_graphics
{
private:
    sf::RectangleShape base1;
    sf::RectangleShape base2;
    sf::RectangleShape baseoutline;
    sf::RectangleShape wall1;
    sf::RectangleShape wall2;
    sf::RectangleShape wall3;
    sf::RectangleShape wall4;
    sf::RectangleShape roof1;
    sf::RectangleShape roof2;

    
public:
    Greenhouse_graphics();
    void draw(sf::RenderWindow& window);
};




