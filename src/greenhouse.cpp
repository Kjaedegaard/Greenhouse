#include<iostream>
#include<math.h>
#include<vector>
#include<unistd.h>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include<imgui.h>
#include<imgui-SFML.h>

#include<diagram.h>
#include<regulator.h>
#include<sensor_sim.h>
#include<plant.h>
#include<tomato_plant.h>
#include<greenhouse_graphics.h>

#include<cooler.h>
#include<heater.h>
#include<humidifier.h>
#include<dehumidifier.h>

void condition_loop(Actuator& actuator1, Actuator& actuator2, Condition& condition, SensorSim& sensor, Regulator& regulator){
    std::vector<double> actuator_info;
    sensor.update_sensor_value(condition.get_condition_value());
    regulator.update(sensor.get_sensor_value());
    actuator_info.push_back(actuator1.actuate(regulator.get_state()));
    actuator_info.push_back(actuator2.actuate(regulator.get_state()));
    condition.update(actuator_info);
    actuator_info.clear();
}

int main(int argc, char const *argv[])
{   
//setup

    // time element used to delay the program
    unsigned int microseconds = 250000;

    //create greenhouse
    Greenhouse_graphics greenhouse_graphics;

    // create vectors with tomatoplants conditions
    std::vector<double> tomato_hum_conditions{42,50};
    std::vector<double> tomato_temp_conditions{22,25};

    // create vectors 
    std::vector<float> plant1_position{150,365};
    std::vector<float> plant2_position{300,365};
    std::vector<float> plant3_position{450,365};

    //create tomato plant 1
    Tomato_plant plant1(tomato_hum_conditions, tomato_temp_conditions, plant1_position);
    plant1.plant_tomato();

    //create tomato plant 2 
    Tomato_plant plant2(tomato_hum_conditions, tomato_temp_conditions, plant2_position);
    plant2.plant_tomato();

    //create tomato plant 3
    Tomato_plant plant3(tomato_hum_conditions, tomato_temp_conditions, plant3_position);
    plant3.plant_tomato();

    // initialize the font by loading the font file placed in the build file
    sf::Font font;
    if(!font.loadFromFile("Digitalt.ttf")){
        std::cout << "Error loading font";
    }
    
    // create vector with coordanates to use as refference in diagram class
    std::vector<float> diagram_pos{650,280};

    // Draw title
    sf::Text title;
    title.setFont(font);
    title.setString("Current\nconditions:");
    title.setCharacterSize(25);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f{diagram_pos[0]-10,diagram_pos[1]-280});

    // Create diagrams displaying conditions, one for each sensor/regulator pair
    Diagram humdiagram(diagram_pos,2,std::string( "H\nu\nm\ni\nd\ni\nt\ny"), sf::Color::Green,std::string("%"));
    Diagram tempdiagram(diagram_pos,3,std::string( "T\ne\nm\np\ne\nr\na\nt\nu\nr\ne"), sf::Color::Red, std::string("C"));
    Diagram livcondiagram(diagram_pos,1,std::string("L\ni\nv\ni\nn\ng\n \nc\no\nn\nd\ni\nt\ni\no\nn\ns\n"), sf::Color::Blue, std::string("%"));
    
    // Create humidity loop objects
    Condition humidity(33,0.4);
    SensorSim humidity_sensor;
    Regulator humidity_regulator(plant1.get_opt_hum_conditions());
    Humidifier humidifier;
    Dehumidifier dehumidifier;
    
    // loop will look like condition_loop(humidifier, dehumidifier, humidity, humidity_sensor, humidity_regulator)

    // create temperature loop objects
    Condition temperature(18, 0.4);
    SensorSim temperature_sensor;
    Regulator temperature_regulator(plant1.get_opt_temp_conditions());
    Cooler cooler;
    Heater heater;

    // loop will look like: condition_loop(heater, cooler, temperature, temperature_sensor, temperature_regulator)

    std::vector<int> reg_states;

/*
    // Create regulators - they take the optimal conditions determined when creating the plant -
    Regulator Humidity_reg(plant1.get_opt_hum_conditions()); 
    Regulator Temp_reg(plant1.get_opt_temp_conditions());
    
*/

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tomato simulator");

//main loop

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //condition loops
        condition_loop(humidifier, dehumidifier, humidity, humidity_sensor, humidity_regulator);
        condition_loop(heater, cooler, temperature, temperature_sensor, temperature_regulator);

        //update plant
        reg_states.clear();
        reg_states.push_back(humidity_regulator.get_state());
        reg_states.push_back(temperature_regulator.get_state());
        plant1.cal_living_conditions(reg_states);
        plant2.cal_living_conditions(reg_states);
        plant3.cal_living_conditions(reg_states);

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(title);
        humdiagram.update_diagram(window, humidity_sensor.get_sensor_value());
        tempdiagram.update_diagram(window, temperature_sensor.get_sensor_value());
        livcondiagram.update_diagram(window, plant1.get_living_conditions());
        plant1.update_tomato(window);
        plant2.update_tomato(window);
        plant3.update_tomato(window);
        greenhouse_graphics.draw(window);

        // end the current frame
        window.display();

        // delay the loop to slow it down
        usleep(microseconds);
        //sleep(1);

    }
    return 0;
}
