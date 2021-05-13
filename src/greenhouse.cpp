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

#include<thread>

// this functions takes a set of actuators, a conition, a sensor and a regulator adnd updates them
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
    std::vector<float> greenhouse_info{230,95,300};
    Greenhouse_graphics greenhouse_graphics(greenhouse_info);

    // create vectors with tomatoplants conditions
    std::vector<double> tomato_hum_conditions{42,50};
    std::vector<double> tomato_temp_conditions{22,25};

    // create vectors 
    std::vector<float> plant1_position{300,365};
    std::vector<float> plant2_position{450,365};
    

    //create tomato plant 1
    Tomato_plant plant1(tomato_hum_conditions, tomato_temp_conditions, plant1_position);
    plant1.plant_tomato();

    //create tomato plant 2 
    Tomato_plant plant2(tomato_hum_conditions, tomato_temp_conditions, plant2_position);
    plant2.plant_tomato();

    // initialize the font by loading the font file placed in the build file
    sf::Font font;
    if(!font.loadFromFile("Digitalt.ttf")){
        std::cout << "Error loading font";
    }
    
    // create vector with coordanates to use as refference in diagram class
    std::vector<float> diagram1_pos{50,280};
    std::vector<float> diagram2_pos{650,280};

    // Draw title
    sf::Text title1;
    title1.setFont(font);
    title1.setString("Current\nconditions:");
    title1.setCharacterSize(25);
    title1.setFillColor(sf::Color::White);
    title1.setPosition(sf::Vector2f{diagram1_pos[0]-10,diagram1_pos[1]-280});

    sf::Text title2;
    title2.setFont(font);
    title2.setString("Current\nconditions 1:");
    title2.setCharacterSize(25);
    title2.setFillColor(sf::Color::White);
    title2.setPosition(sf::Vector2f{diagram2_pos[0]-10,diagram2_pos[1]-280});

    // Create diagrams 1 displaying conditions, one for each sensor/regulator pair
    Diagram humdiagram1(diagram1_pos,2,std::string( "H\nu\nm\ni\nd\ni\nt\ny"), sf::Color::Green,std::string("%"));
    Diagram tempdiagram1(diagram1_pos,3,std::string( "T\ne\nm\np\ne\nr\na\nt\nu\nr\ne"), sf::Color::Red, std::string("C"));
    Diagram livcondiagram1(diagram1_pos,1,std::string("L\ni\nv\ni\nn\ng\n \nc\no\nn\nd\ni\nt\ni\no\nn\ns\n"), sf::Color::Blue, std::string("%"));
    
    // Create diagrams 1 displaying conditions, one for each sensor/regulator pair
    Diagram humdiagram2(diagram2_pos,2,std::string( "H\nu\nm\ni\nd\ni\nt\ny"), sf::Color::Green,std::string("%"));
    Diagram tempdiagram2(diagram2_pos,3,std::string( "T\ne\nm\np\ne\nr\na\nt\nu\nr\ne"), sf::Color::Red, std::string("C"));
    Diagram livcondiagram2(diagram2_pos,1,std::string("L\ni\nv\ni\nn\ng\n \nc\no\nn\nd\ni\nt\ni\no\nn\ns\n"), sf::Color::Blue, std::string("%"));

    // Create humidity1 loop objects
    Condition humidity1(33,0.5);
    SensorSim humidity_sensor1;
    Regulator humidity_regulator1(plant1.get_opt_hum_conditions());
    Humidifier humidifier1(greenhouse_info, 1, 1);
    Dehumidifier dehumidifier1(greenhouse_info, 1, 2);
    
    // loop will look like condition_loop(humidifier, dehumidifier, humidity, humidity_sensor, humidity_regulator)

    // create temperature1 loop objects
    Condition temperature1(18, 0.5);
    SensorSim temperature_sensor1;
    Regulator temperature_regulator1(plant1.get_opt_temp_conditions());
    Cooler cooler1(greenhouse_info, 1, 3);
    Heater heater1(greenhouse_info, 1, 4);
    
    // loop will look like: condition_loop(heater, cooler, temperature, temperature_sensor, temperature_regulator)

    // Create humidity2 loop objects
    Condition humidity2(33,0.4);
    SensorSim humidity_sensor2;
    Regulator humidity_regulator2(plant2.get_opt_hum_conditions());
    Humidifier humidifier2(greenhouse_info, 2, 1);
    Dehumidifier dehumidifier2(greenhouse_info, 2, 2);
    
    // loop will look like condition_loop(humidifier, dehumidifier, humidity, humidity_sensor, humidity_regulator)

    // create temperature2 loop objects
    Condition temperature2(18, 0.4);
    SensorSim temperature_sensor2;
    Regulator temperature_regulator2(plant2.get_opt_temp_conditions());
    Cooler cooler2(greenhouse_info, 2, 3);
    Heater heater2(greenhouse_info, 2, 4);

    // loop will look like: condition_loop(heater, cooler, temperature, temperature_sensor, temperature_regulator)

    std::vector<int> reg_states1;
    std::vector<int> reg_states2;

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

        //condition loops updating all sensors, actuators,  conditions, and regulators
        condition_loop(humidifier1, dehumidifier1, humidity1, humidity_sensor1, humidity_regulator1);
        condition_loop(heater1, cooler1, temperature1, temperature_sensor1, temperature_regulator1);

        condition_loop(humidifier2, dehumidifier2, humidity2, humidity_sensor2, humidity_regulator2);
        condition_loop(heater2, cooler2, temperature2, temperature_sensor2, temperature_regulator2);

        //update plants
        reg_states1.clear();
        reg_states1.push_back(humidity_regulator1.get_state());
        reg_states1.push_back(temperature_regulator1.get_state());
        plant1.cal_living_conditions(reg_states1);

        reg_states2.clear();
        reg_states2.push_back(humidity_regulator2.get_state());
        reg_states2.push_back(temperature_regulator2.get_state());
        plant2.cal_living_conditions(reg_states2);
       

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...

        window.draw(title1);
        window.draw(title2);
        humdiagram1.update_diagram(window, humidity_sensor1.get_sensor_value());
        tempdiagram1.update_diagram(window, temperature_sensor1.get_sensor_value());
        livcondiagram1.update_diagram(window, plant1.get_living_conditions());

        humdiagram2.update_diagram(window, humidity_sensor2.get_sensor_value());
        tempdiagram2.update_diagram(window, temperature_sensor2.get_sensor_value());
        livcondiagram2.update_diagram(window, plant2.get_living_conditions());

        humidifier1.draw_actuator(window);
        humidifier2.draw_actuator(window);

        dehumidifier1.draw_actuator(window);
        dehumidifier2.draw_actuator(window);

        heater1.draw_actuator(window);
        heater2.draw_actuator(window);

        cooler1.draw_actuator(window);
        cooler2.draw_actuator(window);
        
        plant1.update_tomato(window);
        plant2.update_tomato(window);

        greenhouse_graphics.draw(window);

        // end the current frame
        window.display();

        // delay the loop to slow it down
        usleep(microseconds);

    }
    return 0;
}