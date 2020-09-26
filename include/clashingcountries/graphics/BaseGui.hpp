#ifndef CLASHING_COUNTRIES_GRAPHICS_BASEGUI_HPP
#define CLASHING_COUNTRIES_GRAPHICS_BASEGUI_HPP

#include <SFML/Graphics.hpp>
#include "Style.hpp"
#include "RelativeCoordinates.hpp"

namespace clashing_countries {  // the naming convention is inconsistent here because after clashing_countries::graphics everything will match SFML's naming convention
    namespace graphics {
        class BaseGui : public sf::Transformable, public sf::Drawable {
            public:
                clashing_countries::graphics::Style style;
                bool visible = true;
                bool hovered = false;
                int z_index = 0;
                clashing_countries::graphics::RelativeCoordinates relativePosition;

                BaseGui();

                virtual sf::FloatRect getGlobalBounds() const = 0;
                virtual void MouseClickEvent() = 0;
                virtual void MouseHoverEvent() = 0;
                virtual void KeyboardEvent() = 0;
        };
    }
}

#endif