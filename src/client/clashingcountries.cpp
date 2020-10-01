#include <clashingcountries/core_util.hpp>
#include <clashingcountries/graphics.hpp>
#include <clashingcountries/client/client_main.hpp>
using namespace clashing_countries;

std::thread game_thread;
std::thread file_thread;

int main (int argc, char *argv[]) {

    // test

    graphics::util::init_font();
    core_utils::load_config("config.lua");

    graphics::util::renderTarget.create (

        sf::VideoMode(
            int_settings["screen_width"],
            int_settings["screen_height"]
        ),

        "Clashing Countries",

        (bool_settings["fullscreen"]) ? sf::Style::Fullscreen : sf::Style::Default

    );

    std::cout << "Successful, exiting..." << std::endl;

    return 0;

}