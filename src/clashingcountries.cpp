#include <clashingcountries.hpp>
#include <clashingcountries/graphics.hpp>
#include <clashingcountries/extend_script.hpp>

int main () {

    init_lua_config();

    sf::Window w (sf::VideoMode(video_settings["screen_width"], video_settings["screen_height"]), "Clashing Countries");

    return 0;

}