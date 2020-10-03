#include <clashingcountries/graphics/render_util.hpp>



bool clashing_countries::graphics::util::init_font() {
    return clashing_countries::graphics::util::global_font.loadFromFile(FONT_PATH);
}
