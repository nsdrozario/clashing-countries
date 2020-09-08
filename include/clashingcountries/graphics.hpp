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

    class RelativeCoordinates {

        public:

            float x; // range from 0-1 as ratio of screen size
            float y;

            RelativeCoordinates();
            RelativeCoordinates(float x, float y);

            sf::Vector2f getVector() const;

    };

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
            bool hovered = false;
            float padding = 10.0f;
            int z_index = 0;
            RelativeCoordinates relativePosition;

            BaseGui();

            virtual sf::FloatRect getGlobalBounds() const=0;
            virtual void MouseClickEvent()=0;
            virtual void MouseHoverEvent()=0;
            virtual void KeyboardEvent()=0;

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

            // setters
            void setText(std::string text);
            void setPadding(float p);
            virtual void setPosition(float x, float y);
            virtual void setPosition(const sf::Vector2f& position);
            virtual void setPosition(RelativeCoordinates position);

            // getters
            virtual sf::Vector2f getPosition() const;

            // event handlers
            virtual void MouseClickEvent();
            virtual void MouseHoverEvent();
            virtual void KeyboardEvent();

            virtual sf::FloatRect getGlobalBounds() const;

        private:
        
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    };

    class Button : public Label {            

        public:

            std::function<void(Button&)> *callback; 

            // using Label::Label;
            Button();
            Button(Style s, std::string text, std::function<void(Button&)> *f);

            void setBodyHighlightColor(sf::Color c);
            void setTextHighlightColor(sf::Color c);
            void MouseHoverEvent();
            virtual sf::FloatRect getGlobalBounds() const;

            virtual sf::Vector2f getPosition() const;
        private:
            void updateColor();
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
            sf::Color bodyHighlightedColor;
            sf::Color textHighlightedColor;

    };

}

extern sf::RenderWindow renderTarget;
extern std::vector<clc_ui::BaseGui *> RenderQueue; // probably going to change this to use smart pointers later

#endif