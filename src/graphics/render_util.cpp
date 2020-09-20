#include <clashingcountries/graphics/render_util.hpp>
sf::Font text_font;

bool init_font() {

    return text_font.loadFromFile(FONT_PATH);

}
