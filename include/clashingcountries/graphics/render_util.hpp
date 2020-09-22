#ifndef CLASHING_COUNTRIES_GRAPHICS_RENDER_UTIL_HPP
#define CLASHING_COUNTRIES_GRAPHICS_RENDER_UTIL_HPP

#define FONT_PATH "font/OpenSans-Regular.ttf"

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include <queue>
#include <vector>

void draw_to_screen();

namespace clashing_countries {
    namespace graphics {
        class util {
            public:
                static sf::RenderWindow renderTarget;
                static sf::Font global_font;
                static bool init_font();
        };
    }
}

// extern std::vector<clashing_countries::graphics::BaseGui *> RenderQueue; // probably going to change this to use smart pointers later

#endif