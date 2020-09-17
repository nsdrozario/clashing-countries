#ifndef CLASHING_COUNTRIES_GRAPHICS_RENDER_UTIL_HPP
#define CLASHING_COUNTRIES_GRAPHICS_RENDER_UTIL_HPP

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

extern sf::RenderWindow renderTarget;
// extern std::vector<clashing_countries::graphics::BaseGui *> RenderQueue; // probably going to change this to use smart pointers later

#endif