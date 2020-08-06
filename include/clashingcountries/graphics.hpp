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

namespace clc_ui {

    class compound_ui_element { // class to define GUI elements that have multiple SFML elements

        public:
    
            void setXPosAbsolute(double x);
            void setXPosCenter(double x);  
            void setYPosAbsolute(double y);
            void setYPosCenter(double y);
            void setXSize(double x);
            void setYSize(double y);
            void setBackgroundColor(sf::Color c);
            void setOutlineColor(sf::Color c);
            void setOutlineThickness(double x);

            virtual void render(); // this function needs to be overloaded for each gui element

        protected:

            float xpos;
            float ypos;
            double x_size;
            double y_size;
            double outline_thickness;
            sf::Color bg_color;
            sf::Color outline_color;

    };

    class box_label : public compound_ui_element {

        public:

            virtual void render();

        protected:
            sf::RectangleShape body;
            sf::Text label;

    };

    class button : public box_label {

    };

    class input_field : public compound_ui_element {

    };

}

#endif