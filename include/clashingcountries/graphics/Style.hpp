#ifndef CLASHING_COUNTRIES_GRAPHICS_STYLE_HPP
#define CLASHING_COUNTRIES_GRAPHICS_STYLE_HPP

#include <SFML/Graphics.hpp>
#include "render_util.hpp"
#include "RelativeCoordinates.hpp"

namespace clashing_countries {
    namespace graphics {
        class Style {
            public:
                
                // base properties
                sf::Color outlineColor;
                sf::Color backgroundColor;
                sf::Color textColor;
                sf::Font *font;

                float borderThickness;
                bool outlineVisible;
                bool bodyVisible;

                bool visible;
                float padding;

                // hover properties
                sf::Color hoverBackgroundColor;
                sf::Color hoverTextColor;
                sf::Color hoverOutlineColor;

                RelativeCoordinates coords;

                /*
                Style() {
                    font = &util::global_font;
                    outlineColor = sf::Color(255, 255, 255, 255);
                    backgroundColor = sf::Color(0, 0, 0, 255);
                    textColor = sf::Color(255, 255, 255, 255);
                    borderThickness = 1.0f;
                }
                */

                Style(sf::Color bc=sf::Color::White, sf::Color tc=sf::Color::Black, sf::Color oc=sf::Color::Black, float b=1.0f, sf::Font *f=&util::global_font) {
                    font = f;
                    outlineColor = oc;
                    backgroundColor = bc;
                    textColor = tc;
                    borderThickness = b;
                }

        };
    }
}

#endif