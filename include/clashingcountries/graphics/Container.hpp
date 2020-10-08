#ifndef CLASHING_COUNTRIES_GRAPHICS_CONTAINER_HPP
#define CLASHING_COUNTRIES_GRAPHICS_CONTAINER_HPP

#include <SFML/Graphics.hpp>
#include "BaseGui.hpp"
#include <set>

namespace clashing_countries {
    namespace graphics {

        struct ZIndexSort {
            bool operator() (const BaseGui *g1, const BaseGui *g2) const;
        };

        class Container : public BaseGui {
            public:
                std::set<BaseGui *, ZIndexSort> contents; // not a multiset i dont see why you'd need multiple pointers pointing to the same location

                Container();

                void addElement(BaseGui *g);
                void removeElement(BaseGui *g);
                
                virtual void setPosition(const float x, const float y);
                virtual void setPosition(const sf::Vector2f& position);
                // virtual void setPosition(const RelativeCoordinates &position);
                
                virtual sf::FloatRect getGlobalBounds() const;
                virtual sf::Vector2f getPosition() const;

                virtual void MouseClickEvent();
                virtual void MouseHoverEvent();
                virtual void KeyboardEvent();

            private:
                sf::RectangleShape containerBody;
                virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        };
    }
}

#endif