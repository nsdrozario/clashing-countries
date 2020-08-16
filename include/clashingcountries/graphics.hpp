#ifndef CLC_GRAPHICS_HPP
#define CLC_GRAPHICS_HPP

#define FONT_PATH "font/OpenSans-Regular.ttf"

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
extern sf::Font text_font;

bool init_font();
sf::Window gen_window_from_config();
sf::Text gen_label(std::string text, int size);

void draw_to_screen();

namespace clc_ui { // forgive my inconsistent naming conventions

    class BaseGui : public sf::Transformable, sf::Drawable {

    };

    class Button : BaseGui {            

        public:
            std::function<bool> call; // return success or not

    };

    class InputBox : BaseGui {

    };
    
    class Label : BaseGui {

        public:
            bool BodyVisible;

    };


}

#endif