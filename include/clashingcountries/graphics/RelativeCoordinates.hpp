#ifndef CLASHING_COUNTRIES_GRAPHICS_RELATIVECOORDINATES_HPP
#define CLASHING_COUNTRIES_GRAPHICS_RELATIVECOORDINATES_HPP

#include <SFML/Graphics.hpp>

namespace clashing_countries {
    namespace graphics {

        class RelativeCoordinates {

            public:

                float x; // range from 0-1 as ratio of screen size
                float y;

                RelativeCoordinates();
                RelativeCoordinates(float x, float y);

                sf::Vector2f getVector() const;

        };

    }
}

#endif