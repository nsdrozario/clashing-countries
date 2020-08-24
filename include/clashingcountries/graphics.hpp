#ifndef CLC_GRAPHICS_HPP
#define CLC_GRAPHICS_HPP

#define FONT_PATH "font/OpenSans-Regular.ttf"

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include <queue>
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

            Style() {
                font = &text_font;
                outlineColor = sf::Color(255,255,255,255);
                backgroundColor = sf::Color(0,0,0,255);
                textColor = sf::Color(255,255,255,255);
                borderThickness = 1.0f;
            }

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

    class BaseGui : public sf::Transformable, public sf::Drawable {

        public:

            Style style;
            bool visible = true;
            
            BaseGui();
    };

    class Container : BaseGui {
        
        public:
            std::priority_queue<BaseGui> elements;

            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;


    };

    class Button : BaseGui {            

        public:

            sf::RectangleShape btnBody;
            sf::Text btnText;
            
          //  std::function<bool> call; // return success or not

    };

    class InputBox : BaseGui {

    };
    
    class Label : public BaseGui {
        public:

            sf::RectangleShape labelBody;
            sf::Text labelText;

            Label(Style s, std::string text);

            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    };


}

#endif