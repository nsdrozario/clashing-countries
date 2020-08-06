#ifndef CLC_GRAPHICS_HPP
#define CLC_GRAPHICS_HPP

#define FONT_PATH "font/OpenSans-Regular.ttf"

#include <SFML/Graphics.hpp>
#include <string>
extern sf::Font text_font;

bool init_font();
sf::Window gen_window_from_config();
sf::Text gen_label(std::string text, int size);

void draw_to_screen();

namespace clc_ui {

    class compound_ui_element { // class to define GUI elements that have multiple SFML elements

        public:
    
            void setXPosAbsolute(float x);
            void setXPosCenter(float x);  
            void setYPosAbsolute(float y);
            void setYPosCenter(float y);
            void setXSize(float x);
            void setYSize(float y);
            void setBackgroundColor(sf::Color c);
            void setOutlineColor(sf::Color c);
            void setOutlineThickness(float x);

            virtual void render(sf::RenderWindow& w) = 0; // this function needs to be overloaded for each gui element

        protected:

            float xpos = 0.f;
            float ypos = 0.f;
            float x_size = 1.f;
            float y_size = 1.f;
            float outline_thickness = 5.0f;
            sf::Color bg_color;
            sf::Color outline_color;

    };

    class box_label : public compound_ui_element {

        public:

            virtual void render(sf::RenderWindow& w);
            void setTextColor(sf::Color c);
            void setTextSize(int x);
            void setLabelText(std::string text);

        protected:
            
            int text_size;
            sf::Color text_color;

            sf::RectangleShape body;
            sf::Text label;


    };

    class button : public box_label {

    };

    class input_field : public compound_ui_element {

    };

}

#endif