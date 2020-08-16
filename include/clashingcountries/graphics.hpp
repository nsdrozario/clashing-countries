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

    class Style {

        public:
            sf::Color outlineColor;
            sf::Color backgroundColor;
            sf::Color textColor;
            sf::Font *font;

            float borderThickness;

            bool outlineVisible;
            bool bodyVisible;

            Style(sf::Font *f, sf::Color bc, sf::Color tc, sf::Color oc, float b) {
                font = f;
                outlineColor = oc;
                backgroundColor = bc;
                textColor = tc;
                borderThickness = b;
            }
            
            Style(sf::Font *f, sf::Color bc, sf::Color tc) {
                font = f;
                outlineColor = sf::Color(0,0,0,255);
                backgroundColor = bc;
                textColor = tc;
                borderThickness = 1.0f;
            }
            
    };

    class BaseGui : public sf::Transformable, sf::Drawable {

        public:

            Style style;

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