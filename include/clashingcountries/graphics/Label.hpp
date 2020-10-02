#ifndef CLASHING_COUNTRIES_GRAPHICS_LABEL_HPP
#define CLASHING_COUNTRIES_GRAPHICS_LABEL_HPP

#include <SFML/Graphics.hpp>
#include "BaseGui.hpp"
#include "Style.hpp"

namespace clashing_countries {
    namespace graphics {
        class Label : public BaseGui {
            public:
                sf::RectangleShape labelBody;
                sf::Text labelText;

                Label();
                Label(Style s, std::string text);

                // setters
                void setText(std::string text);
                void setPadding(float p);
                virtual void setPosition(const float x, const float y);
                virtual void setPosition(const sf::Vector2f& position);
                // virtual void setPosition(const RelativeCoordinates &position);

                // getters
                virtual sf::Vector2f getPosition() const;

                // event handlers
                virtual void MouseClickEvent();
                virtual void MouseHoverEvent();
                virtual void KeyboardEvent();

                virtual sf::FloatRect getGlobalBounds() const;

            private:
            
                virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        };
    }
}

#endif