#include <clashingcountries/graphics.hpp>
#include <iostream>
using namespace clashing_countries::graphics;

void Button::setBodyHighlightColor(sf::Color c) {

    bodyHighlightedColor = c;

}

void Button::setTextHighlightColor(sf::Color c) {

    textHighlightedColor = c;

}

sf::FloatRect Button::getGlobalBounds() const {

    return labelBody.getGlobalBounds();

}

Button::Button() {

    style = Style();
    style.borderThickness = 10.0f;

    labelBody.setFillColor(style.backgroundColor);
    labelBody.setOutlineColor(style.outlineColor);
    labelBody.setOutlineThickness(style.borderThickness);

    labelText.setFont(*style.font);
    labelText.setFillColor(style.textColor);
    labelBody.setSize(sf::Vector2f(100.0f, 50.0f));

    callback = nullptr;

}

Button::Button(Style s, std::string text="Default text") {

    style = s;

    labelBody.setFillColor(s.backgroundColor);
    labelBody.setOutlineColor(s.outlineColor);
    labelBody.setOutlineThickness(s.borderThickness);

    labelText.setFont(*s.font);
    labelText.setString(text);
    labelText.setFillColor(s.textColor);
    sf::FloatRect text_size = labelText.getGlobalBounds();
    labelBody.setSize(sf::Vector2f(text_size.width, text_size.height));



}

void Button::MouseHoverEvent() {

    if (this->hovered) {

        labelBody.setFillColor(style.hoverBackgroundColor);
        labelText.setFillColor(style.hoverTextColor);
        labelBody.setOutlineColor(style.hoverOutlineColor);
        
    } else {

        labelBody.setFillColor(style.backgroundColor);
        labelText.setFillColor(style.textColor);
        labelBody.setOutlineColor(style.outlineColor);

    }

}

sf::Vector2f Button::getPosition() const {
    return labelBody.getPosition();
}

void Button::draw(sf::RenderTarget &t, sf::RenderStates s) const {

    if (this->visible) {
        if (this->style.bodyVisible) {
            t.draw(labelBody);
        }
        if (this->style.outlineVisible) {
            t.draw(labelText);
        }   
    }

}