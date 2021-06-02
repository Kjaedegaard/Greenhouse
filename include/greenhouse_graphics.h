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
    sf::RectangleShape roof1;

public:
    Greenhouse_graphics(std::vector<float> greenhouse_info);
    void draw(sf::RenderWindow& window);
};




