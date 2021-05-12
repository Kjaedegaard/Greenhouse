#include<greenhouse_graphics.h>

Greenhouse_graphics::Greenhouse_graphics(){

    float start_x = 230;
    float lenght = 300;
    float roof_length = 300;

    base1.setFillColor({101,67,33});
    base1.setPosition(sf::Vector2f{start_x,450});
    base1.setSize(sf::Vector2f{lenght,75});

    base2.setFillColor({101,67,33});
    base2.setPosition(sf::Vector2f{start_x,365});
    base2.setSize(sf::Vector2f{lenght,75});

    baseoutline.setFillColor(sf::Color::Black);
    baseoutline.setOutlineColor({101,67,33});
    baseoutline.setOutlineThickness(5.f);
    baseoutline.setPosition(sf::Vector2f{start_x,365});
    baseoutline.setSize(sf::Vector2f{lenght,160});

    wall1.setFillColor(sf::Color::White);
    wall1.setPosition(sf::Vector2f{start_x - 5 ,95});
    wall1.setSize(sf::Vector2f{10,265});

    wall2.setFillColor(sf::Color::White);
    wall2.setPosition(sf::Vector2f{start_x+lenght/2 -5, 95});
    wall2.setSize(sf::Vector2f{10,265});

    wall3.setFillColor(sf::Color::White);
    wall3.setPosition(sf::Vector2f{start_x+lenght-5, 95});
    wall3.setSize(sf::Vector2f{10,265});

    /*
    wall4.setFillColor(sf::Color::White);
    wall4.setPosition(sf::Vector2f{start_x+lenght-5, 95});
    wall4.setSize(sf::Vector2f{10,265});
    */

    roof1.setFillColor(sf::Color::White);
    roof1.setPosition(sf::Vector2f{start_x-5,95});
    roof1.setSize(sf::Vector2f{roof_length,10});
}

void Greenhouse_graphics::draw(sf::RenderWindow& window){
    window.draw(baseoutline);
    window.draw(base1);
    window.draw(base2);
    window.draw(wall1);
    window.draw(wall2);
    window.draw(wall3);
    window.draw(wall4);
    window.draw(roof1);
    window.draw(roof2);
}
