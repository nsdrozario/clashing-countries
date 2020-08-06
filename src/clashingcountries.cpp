#include <clashingcountries.hpp>
#include <clashingcountries/graphics.hpp>
#include <clashingcountries/extend_script.hpp>

// global vars 
sf::RenderWindow w;
sf::Mouse mouse;
clc_ui::box_label test_label;

void draw_to_screen() { // what to draw on screen

    sf::Text title = gen_label("Clashing Countries", 60);
    w.draw(title);
    test_label.render(w);

}

int main () { // main thread

    init_lua_config(); // load config file
    w.create(sf::VideoMode(int_settings["screen_width"], int_settings["screen_height"]), "Clashing Countries", (bool_settings["fullscreen"]) ? sf::Style::Default : sf::Style::Fullscreen); // iniitalize window

    test_label.setLabelText("Hello World");
    test_label.setBackgroundColor(sf::Color(0,0,0,75));
    test_label.setOutlineColor(sf::Color(0,0,255,255));
    test_label.setOutlineThickness(5.0f);
    test_label.setXPosAbsolute(100);
    test_label.setYPosAbsolute(100);

    if (!init_font()) { // load font
        std::cerr << "error opening font" << std::endl;
    }

    while (w.isOpen()) {

        sf::Event e;
        
        while (w.pollEvent(e)) {

            if (e.type == sf::Event::Closed) {

                w.close();
            
            } else if (e.type == sf::Event::MouseButtonPressed) {



            } else if (e.type == sf::Event::KeyPressed) {

                

            }

            w.clear(sf::Color::Black);

            draw_to_screen();

            w.display();

        }

    }

    return 0;

}