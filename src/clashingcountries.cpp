#include <iostream>
#include <cmdlineproc.hpp>
// #include <clashingcountries.hpp>
#include <clashingcountries/graphics.hpp>
#include <clashingcountries/extend_script.hpp>

// global vars 
sf::RenderWindow w;
sf::Mouse mouse;

int main () { // main thread

    cmdlineproc::cmd_args c;
    c.set_flag("--no-gui");
    
    load_config(); // load config file
    
    if (std::find(c.flags.begin(), c.flags.end(), std::string("--no-gui")) != c.flags.end() ) {

        std::cout << "Clashing Countries" << std::endl;    
        exit(0);
        
    } else {

        w.create(sf::VideoMode(int_settings["screen_width"], int_settings["screen_height"]), "Clashing Countries", (bool_settings["fullscreen"]) ? sf::Style::Default : sf::Style::Fullscreen); // iniitalize window
    
    }

    if (!init_font()) { // load font
        std::cerr << "error opening font" << std::endl;
    }

    clc_ui::Style s(&text_font, sf::Color(50,50,50,255), sf::Color(255,0,255,255));
    clc_ui::Label label(s, "Clashing Countries");
    
    while (w.isOpen()) {

        sf::Event e;
        
        while (w.pollEvent(e)) {

            if (e.type == sf::Event::Closed) {

                w.close();
            
            } else if (e.type == sf::Event::MouseButtonPressed) {



            } else if (e.type == sf::Event::KeyPressed) {

                

            }

            w.clear(sf::Color::Black);

            w.draw(label);

            w.display();

        }

    }

    return 0;

}