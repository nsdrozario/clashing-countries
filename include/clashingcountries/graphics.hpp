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
            float padding = 10.0f;

            BaseGui();
    };

    class Container : BaseGui {
        
        public:
        
            std::priority_queue<BaseGui> elements;
        
        private:
        
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;


    };

    class InputBox : BaseGui {

    };
    
    class Label : public BaseGui {
        public:

            sf::RectangleShape labelBody;
            sf::Text labelText;

            Label();
            Label(Style s, std::string text);

            void setText(std::string text);
            void setPadding(float p);

        private:
        
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    };

    class Button : public BaseGui, public Label {            

        public:

            std::function<void()> callback; 

            using Label::Label;
            Button(Style s, std::string text, std::function<void()> f);

            void setBodyHightlightColor(sf::Color c);
            void setTextHighlightColor(sf::Color c);

            

        private:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
            sf::Color bodyHighlightedColor;
            sf::Color textHighlightedColor;

    };

}

#endif
