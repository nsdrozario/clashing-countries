#include <clashingcountries/core_util.hpp>
#include <clashingcountries/graphics.hpp>
#include <clashingcountries/client/client_main.hpp>
using namespace clashing_countries;

// std::thread game_thread;
// std::thread file_thread;

// define static members
sf::Font clashing_countries::graphics::util::global_font;
sf::RenderWindow clashing_countries::graphics::util::renderTarget;

sf::Event event;

int main (int argc, char *argv[]) {

    // test

    clashing_countries::graphics::util::init_font();
    core_utils::load_config("config.lua");

    graphics::util::renderTarget.create (

        sf::VideoMode(
            int_settings["screen_width"],
            int_settings["screen_height"]
        ),

        "Clashing Countries",

        (bool_settings["fullscreen"]) ? sf::Style::Fullscreen : sf::Style::Default

    );

    
    graphics::Container c;
    graphics::Label label;
    label.setText("Clashing Countries");
    c.contents.insert(&label);

    while (graphics::util::renderTarget.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            // save data
            graphics::util::renderTarget.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            // iterate through all elements that accept mouseclicks and if they are in the same position as the mouse, call its event handler method
        } else if (event.type == sf::Event::MouseMoved) {
            // same thing as above except call the handler for mouse movement
        } else if (event.type == sf::Event::KeyPressed) {
            // same as above but with keyboard handlers
        }

        graphics::util::renderTarget.draw(label);

    } 

    std::cout << "Successful, exiting..." << std::endl;

    return 0;

}