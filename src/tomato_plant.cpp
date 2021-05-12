#include<tomato_plant.h>
#include<plant.h>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include<tomato.h>
#include<tomato_branch.h>
#include<iostream>

// function - when it is called the tomato plant will be shown on screen 
void Tomato_plant::plant_tomato(){
    plant_base.setPosition(sf::Vector2f{plant_position[0],plant_position[1]-height});
    plant_base.setSize({height, width});
    plant_base.setOutlineColor(sf::Color::Green);
}

// function updating the tomato plants height, color and width, internal function only called by update_tomato()
void Tomato_plant::grow(){
    if(living_conditions > 80){
        plant_base.setFillColor(sf::Color::Green);

        if (height < 200){
            height = height + 1*living_conditions/100;
            
        }
        else if (height > 200){
            height = height;
        }

         if(width < 10){
            width = width + 0.3;
        }
        else{
            width = width;        
        }
        

        // create branch if height is fitting. branches height is fixed
        if(49 < height and height < 50){
            create_branch(1);
            height = height + 1;
        }
        else if (74 < height and height < 75){
            create_branch(2);
            height = height + 1;
        }
        else if (104 < height and height < 105){
            create_branch(1);
            height = height + 1;
        }
        else if (144 < height and height < 145) {
            create_branch(2);
            height = height + 1;
        }
        else if (173 < height and height < 174){
            create_branch(1);
            height = height + 1;
        }

       
    }

    // if living conditions is lower than 80 the plant wont grow and the color of the stalk will change to yellow
    else if (living_conditions >= 50 and living_conditions <= 80)
    {
        plant_base.setFillColor(sf::Color::Yellow);
    }
    
    // if living conditions drops lower than 50 the plant will die (ish)
    else if (living_conditions < 50)
    {   
        plant_base.setFillColor(sf::Color::Red);
        double temp_width = width;
        width = height;
        height = temp_width;
    }

    plant_base.setSize(sf::Vector2f{width,-height});
}

// function updates plants and branches, then draws them on window
void Tomato_plant::update_tomato(sf::RenderWindow& window){

    grow();
    window.draw(plant_base);

    for(auto &&i : branches){
        i.update_branch(window);
    }
}

// function that create instance of branc class and adds it to vector with branches
void Tomato_plant::create_branch(int side){
    std::vector<float> current_pos;
    current_pos.push_back(plant_position[0]);
    current_pos.push_back(plant_position[1]-height);
    Branch branch(side, current_pos);
    branches.push_back(branch);
}
