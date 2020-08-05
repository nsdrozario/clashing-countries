#include <clashingcountries.hpp>
#include <clashingcountries/graphics.hpp>
#include <clashingcountries/extend_script.hpp>

int main () {

    init_lua_config();

    sf::RenderWindow w (sf::VideoMode(video_settings["screen_width"], video_settings["screen_height"]), "Clashing Countries");

    while (w.isOpen()) {

        sf::Event e;
        
        while (w.pollEvent(e)) {

            if (e.type == sf::Event::Closed) {

                w.close();
            
            } else if (e.type == sf::Event::MouseButtonPressed) {



            } else if (e.type == sf::Event::KeyPressed) {



            }

            w.clear(sf::Color::Black);

    

            w.display();

        }

    }

    return 0;

}