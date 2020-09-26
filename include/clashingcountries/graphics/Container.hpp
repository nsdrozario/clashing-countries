#ifndef CLASHING_COUNTRIES_GRAPHICS_CONTAINER_HPP
#define CLASHING_COUNTRIES_GRAPHICS_CONTAINER_HPP

#include <SFML/Graphics.hpp>
#include "BaseGui.hpp"
#include <set>

namespace clashing_countries {
    namespace graphics {

        struct ZIndexSort {
            bool operator() (const BaseGui *g1, const BaseGui *g2);
        };

        class Container : public BaseGui {
            public:
                std::set<BaseGui *, ZIndexSort> contents;

                void addElement(BaseGui *g);
                void removeElement(BaseGui *g);
                

            private:
                sf::RectangleShape containerBody;
                virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        };
    }
}

#endif