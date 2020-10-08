#include <clashingcountries/graphics/render_util.hpp>

sf::Font clashing_countries::graphics::util::global_font;
sf::RenderWindow clashing_countries::graphics::util::renderTarget;

bool clashing_countries::graphics::util::init_font() {
    return clashing_countries::graphics::util::global_font.loadFromFile(FONT_PATH);
}
