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

namespace clc_ui {

    class button {

        public:
            
            void render(sf::Window w);
            void setColor(sf::Color c);
            void setXPos(int x);
            void setYPos(int y);
            void setPos(int x, int y);
            void setOutlineColor(sf::Color c);
            void setOutlineThickness(sf::Color c);

            // callback event function member is needed
            
        private:

            int size_x;
            int size_y;
            int pos_x;
            int pos_y;
            sf::Color color;
            sf::RectangleShape body;
            sf::Text label;
            

    };
    
    class input_field {
        
        

    };


}

#endif