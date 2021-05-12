#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>

// class showing containing the objects used to display the diagrams with sensordata
class Diagram{
private:
    sf::RectangleShape diagram;
    sf::RectangleShape outline;
    sf::Text current_value;
    sf::Text m_name;
    sf::Font m_font;
    float pos_ref_x;
    float pos_ref_y;
    std::string m_unit;

public:
    void update_diagram(sf::RenderWindow& window, float sensorvalue);
    Diagram(std::vector<float> diagram_positions, int diagram_number, std::string name, sf::Color color, std::string unit);
    
};
