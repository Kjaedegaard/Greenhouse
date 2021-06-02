#include<greenhouse_graphics.h>

Greenhouse_graphics::Greenhouse_graphics(std::vector<float> greenhouse_info){
    
    float start_x = greenhouse_info[0];
    float start_y = greenhouse_info[1];
    float length = greenhouse_info[2];

    float roof_length = 300;

    base1.setFillColor({101,67,33});
    base1.setPosition(sf::Vector2f{start_x,start_y+355});
    base1.setSize(sf::Vector2f{length,75});

    base2.setFillColor({101,67,33});
    base2.setPosition(sf::Vector2f{start_x,start_y+270});
    base2.setSize(sf::Vector2f{length,75});

    baseoutline.setFillColor(sf::Color::Black);
    baseoutline.setOutlineColor({101,67,33});
    baseoutline.setOutlineThickness(5.f);
    baseoutline.setPosition(sf::Vector2f{start_x,start_y+270});
    baseoutline.setSize(sf::Vector2f{length,160});

    wall1.setFillColor(sf::Color::White);
    wall1.setPosition(sf::Vector2f{start_x - 5 ,start_y});
    wall1.setSize(sf::Vector2f{10,265});

    wall2.setFillColor(sf::Color::White);
    wall2.setPosition(sf::Vector2f{start_x+length/2 -5, start_y});
    wall2.setSize(sf::Vector2f{10,265});

    wall3.setFillColor(sf::Color::White);
    wall3.setPosition(sf::Vector2f{start_x+length-5, start_y});
    wall3.setSize(sf::Vector2f{10,265});

    roof1.setFillColor(sf::Color::White);
    roof1.setPosition(sf::Vector2f{start_x-5,start_y});
    roof1.setSize(sf::Vector2f{roof_length,10});
}

void Greenhouse_graphics::draw(sf::RenderWindow& window){
    window.draw(baseoutline);
    window.draw(base1);
    window.draw(base2);
    window.draw(wall1);
    window.draw(wall2);
    window.draw(wall3);
    window.draw(roof1);

}
