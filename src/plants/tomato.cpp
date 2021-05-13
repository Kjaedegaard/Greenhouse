#include<tomato.h>

//constructor
Tomato::Tomato(std::vector<float> coordinates)
{
    // save coordinates internally, same as in tomato branch
    tomato_position = coordinates;

    //setup
    tomato_obj.setPosition(sf::Vector2f{tomato_position[0],tomato_position[1]});
    tomato_obj.setFillColor(sf::Color::Green);
    //tomato_obj.setOutlineColor(sf::Color::Red);
    tomato_obj.setRadius(tomato_size);
}

// grow function, the same as in tomato branch, on called by update function. Updates size and color of tomato
void Tomato::grow(){
    
    if(tomato_size < 5.5){
        tomato_size = tomato_size + 0.02;
    }
    else if (tomato_size >= 5.5){
        tomato_size = tomato_size;
        tomato_obj.setFillColor(sf::Color::Red);
    }

    tomato_obj.setRadius(tomato_size);    
}

// function called from outside class, updating the tomato and drawing it on window
void Tomato::update(sf::RenderWindow& window){
    grow();
    window.draw(tomato_obj);
}