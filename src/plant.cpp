#include<plant.h>
#include<vector>
#include<iostream>

// contructor for the plant base class, saves information internally
Plant::Plant(std::vector<double> hum_conditions, std::vector<double> temp_conditions, std::vector<float> coordinates){

    plant_opt_hum_conditions = hum_conditions;
    plant_opt_temp_conditions = temp_conditions;
    plant_position = coordinates;
}

// function that recalculates the living conditions based on the current regulator states
void Plant::cal_living_conditions(std::vector<int> regulator_states){
    
    for(auto &&i : regulator_states){
        
        switch (i)
        {
        case 1:
            living_conditions = living_conditions + 8/regulator_states.size();
            
            break;

        case 2 & 3:
            living_conditions = living_conditions -8/regulator_states.size();
            break;
        }
        if(living_conditions < 0){
            living_conditions = 0;
        }
        else if(living_conditions >= 100){
            living_conditions = 100;
        }
    }
}
