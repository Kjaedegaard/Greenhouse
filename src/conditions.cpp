#include<sensor_sim.h>
#include<iostream>
#include<ctime>
#include<unistd.h>
#include<conditions.h>

Condition::Condition(double start_value, double change_factor){
    condition_value = start_value;
    change_speed = change_factor;
}


void Condition::update_random(){
    srand(time(0));

    // rnadom_int is assiged as either true or false
    bool random_bool = std::rand() %2 ;

    if(random_bool == true)
    {
        condition_value +=  change_speed;        
    }
    else
    {
        condition_value -= change_speed;
    }    

    //could be done like this:
    //condition_value = random_int? condition_value -= change_speed : condition_value +=  change_speed;

}

void Condition::update_condition(){

    update_random();
    for(auto &&i : actuator_informations){
        condition_value = condition_value + i;
        std::cout << "actuator value "<< i << "\n";
    }
}

void Condition::update(std::vector<double> actuator_info){
    actuator_informations = actuator_info;
    update_condition();
}