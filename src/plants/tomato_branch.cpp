#include<tomato_branch.h>
#include<tomato.h>
#include<iostream>

// contructor
Branch::Branch(int side, std::vector<float> current_pos){ 

    branch.setFillColor(sf::Color::Green); // color set to green
    // saving the arguement in internal data

    position = current_pos;

    // based on which side of the plant the branch will be placed, the growing direction is initialized, the vector contains two values due to 
    if(side == 1){
        growing_direction = -1;
        
    }
    else if (side == 2){
        growing_direction = 1;     
    }
    branch.setPosition(sf::Vector2f{position[0], position[1]});
}

// Internal function only called by the public update function, it updates the branch lenght and branc width. it also
// calls the private function set_tomato_pair() when the lenght of the branch is fitting
void Branch::grow(){

    if(branch_lenght<50){
        branch_lenght = branch_lenght+1;
    }
    if(branch_width < 7){
        branch_width=branch_width+0.3;
    }
    
    // explain growing direction
    branch.setSize(sf::Vector2f{branch_lenght*growing_direction,branch_width});   

    //tomato planting - tomatoes at placed at prespecified points atm.
    int temporary_length = branch_lenght; // swich only takes values of typ integer, therefore the beanch lenght is change here. always round down
    switch (temporary_length)
    {
    case 20:
        set_tomato_pair();
        break;
    case 35:
        set_tomato_pair();
        break;
    case 50:
        set_tomato_pair();
        break;
    default:
        break;
    }
}

void Branch::update_branch(sf::RenderWindow& window ){

    grow();
    window.draw(branch);

    for(auto &&i : tomatoes){
        i.update(window);
    }
}


// Function creating instances of the tomato class and storing them in the tomatoes vector
void Branch::set_tomato_pair(){

    //create tomato six pixels under branch
    std::vector<float> tomato_loc1{position[0] + branch_lenght*growing_direction, position[1] + 6};
    Tomato tomato1(tomato_loc1);
    tomatoes.push_back(tomato1);

    // create tomato above branch
    std::vector<float> tomato_loc2{position[0] + branch_lenght*growing_direction, position[1] - 12};
    Tomato tomato2(tomato_loc2);
    tomatoes.push_back(tomato2);
}