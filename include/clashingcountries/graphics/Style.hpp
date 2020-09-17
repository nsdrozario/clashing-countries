#ifndef CLASHING_COUNTRIES_GRAPHICS_STYLE_HPP
#define CLASHING_COUNTRIES_GRAPHICS_STYLE_HPP

#include <SFML/Graphics.hpp>
#include "render_util.hpp"

namespace clashing_countries {
    namespace graphics {
        class Style {
            public:
                sf::Color outlineColor;
                sf::Color backgroundColor;
                sf::Color textColor;
                sf::Font *font;

                float borderThickness;

                bool outlineVisible;
                bool bodyVisible;

                Style() {
                    font = &text_font;
                    outlineColor = sf::Color(255, 255, 255, 255);
                    backgroundColor = sf::Color(0, 0, 0, 255);
                    textColor = sf::Color(255, 255, 255, 255);
                    borderThickness = 1.0f;
                }

                Style(sf::Font *f, sf::Color bc, sf::Color tc, sf::Color oc, float b) {
                    font = f;
                    outlineColor = oc;
                    backgroundColor = bc;
                    textColor = tc;
                    borderThickness = b;
                }

                Style(sf::Font *f, sf::Color bc, sf::Color tc) {
                    font = f;
                    outlineColor = sf::Color(0, 0, 0, 255);
                    backgroundColor = bc;
                    textColor = tc;
                    borderThickness = 1.0f;
                }

        };
    }
}

#endif