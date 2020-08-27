#include <clashingcountries/graphics.hpp>
using namespace clc_ui;

Button::Button() {

    style = Style(&text_font, sf::Color(255,255,255,255), sf::Color(0,0,0,255), sf::Color(0,0,0,255), 10.0f);
    labelBody.setFillColor(style.backgroundColor);
    labelBody.setOutlineColor(style.outlineColor);
    labelBody.setOutlineThickness(style.borderThickness);

    labelText.setFont(*style.font);
    labelText.setFillColor(style.textColor);
    labelBody.setSize(sf::Vector2f(100.0f, 50.0f));

    callback = nullptr;

}

Button::Button(Style s, std::string text, std::function<void(Button&)> *f) {

    style = s;

    labelBody.setFillColor(s.backgroundColor);
    labelBody.setOutlineColor(s.outlineColor);
    labelBody.setOutlineThickness(s.borderThickness);

    labelText.setFont(*s.font);
    labelText.setString(text);
    labelText.setFillColor(s.textColor);
    sf::FloatRect text_size = labelText.getGlobalBounds();
    labelBody.setSize(sf::Vector2f(text_size.width, text_size.height));

    callback = f;

}

void Button::updateColor() { // this needs to be called by some rendering function

    if (labelBody.getGlobalBounds().contains((float) sf::Mouse::getPosition().x, (float) sf::Mouse::getPosition().y)) {

        labelBody.setFillColor(bodyHighlightedColor);
        labelText.setFillColor(textHighlightedColor);

    } else {

        labelBody.setFillColor(style.backgroundColor);
        labelBody.setFillColor(style.textColor);

    }

}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(labelBody);
    target.draw(labelText);

}