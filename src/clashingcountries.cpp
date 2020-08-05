#include <clashingcountries.hpp>
#include <clashingcountries/graphics.hpp>
#include <clashingcountries/extend_script.hpp>

sf::RenderWindow w;

void draw_to_screen() {

    sf::Text title = gen_label("Clashing Countries", 60);
    w.draw(title);
}

int main () {

    init_lua_config();

    w.create(sf::VideoMode(video_settings["screen_width"], video_settings["screen_height"]), "Clashing Countries");

    if (!init_font()) {
        std::cout << "error opening font" << std::endl;
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