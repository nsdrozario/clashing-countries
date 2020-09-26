#ifndef CLASHING_COUNTRIES_GRAPHICS_BUTTON_HPP
#define CLASHING_COUNTRIES_GRAPHICS_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include "BaseGui.hpp"
#include "Style.hpp"
#include "Label.hpp"

namespace clashing_countries { 

    namespace graphics {

        class Button : public Label {            

            public:

                std::function<void(Button&)> *callback; 

                // using Label::Label;
                Button();
                Button(Style s, std::string text);

                void setBodyHighlightColor(sf::Color c);
                void setTextHighlightColor(sf::Color c);
                void MouseHoverEvent();
                virtual sf::FloatRect getGlobalBounds() const;

                virtual sf::Vector2f getPosition() const;
            private:
                void updateColor();
                virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
                sf::Color bodyHighlightedColor;
                sf::Color textHighlightedColor;

        };

    }
}

#endif