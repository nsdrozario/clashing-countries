#include <clashingcountries/graphics.hpp>

sf::Font text_font;

bool init_font() {

    return text_font.loadFromFile(FONT_PATH);

}

sf::Text gen_label(std::string text, int size) {

    sf::Text t (text, text_font, size);

    return t;

}