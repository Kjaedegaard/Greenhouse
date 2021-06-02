#include<diagram.h>
#include<vector>
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

// constructor
Diagram::Diagram(std::vector<float> diagram_positions, int diagram_number, std::string name, sf::Color color, std::string unit){

    //init values given as parameters
    m_unit = unit;
    
    //load the font
    if(!m_font.loadFromFile("res\\fonts\\Digitalt.ttf")){
        std::cout << "Error loading font";
    }

    //load postion of diagram based values given in parametes
    pos_ref_x = diagram_positions[0]+(diagram_number-1)*35;
    pos_ref_y = diagram_positions[1];

    //init diagram collumn
    diagram.setSize(sf::Vector2f{10,0});
    diagram.setFillColor(color);
    diagram.setPosition(sf::Vector2f{pos_ref_x, pos_ref_y});

    //init ouline of collumn
    outline.setSize(sf::Vector2f{14,200});
    outline.setFillColor(sf::Color::Black);
    outline.setOutlineThickness(1.f);
    outline.setOutlineColor(sf::Color::White);
    outline.setPosition(sf::Vector2f{pos_ref_x-2,pos_ref_y  -200 +2});

    //init name of connected sensor based on name given as parameter :: every letter needs to be seperated by \n
    m_name.setFont(m_font);
    m_name.setString(name);
    m_name.setPosition(sf::Vector2f{pos_ref_x, pos_ref_y + 10});
    m_name.setCharacterSize(14);

    //init the display of current value
    current_value.setFont(m_font);
    current_value.setPosition(sf::Vector2f{pos_ref_x - 8 , pos_ref_y - 215});
    current_value.setCharacterSize(13);

}

//function used to update the diagram
void Diagram::update_diagram(sf::RenderWindow& window, float sensorvalue){

    diagram.setSize(sf::Vector2f{10,sensorvalue*2});                        //update the lenght of the collumn based on sensorvalue given i parameters
    diagram.setPosition(sf::Vector2f{pos_ref_x,pos_ref_y-sensorvalue*2});   //update the starting point of the collumn :: the collumn is oriented downwards so starting point is regulated to match at fixed bottom
    int sensorvalue_as_int = sensorvalue;                                   //the displayed value will be shown with no decimals, therefore the sensorvalue will be converted to int
    current_value.setString(std::to_string(sensorvalue_as_int)+m_unit);     //update the displayed value

    // draw the different objects for the to be displayes later
    window.draw(outline);
    window.draw(diagram);
    window.draw(m_name);
    window.draw(current_value);
}