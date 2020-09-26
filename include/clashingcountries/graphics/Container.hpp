#ifndef CLASHING_COUNTRIES_GRAPHICS_CONTAINER_HPP
#define CLASHING_COUNTRIES_GRAPHICS_CONTAINER_HPP

#include <SFML/Graphics.hpp>
#include "BaseGui.hpp"

namespace clashing_countries {
    namespace graphics {
        class Container : public BaseGui {
            public:
                std::priority_queue<BaseGui> elements;
            private:
                virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        };
    }
}

#endif