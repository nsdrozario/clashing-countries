#include <clashingcountries/graphics.hpp>
using namespace clc_ui;

Label::Label() {

    style = Style(&text_font, sf::Color(0,0,0,150), sf::Color(255,255,255,255), sf::Color(255,255,255,255), 10.0f);
    labelBody.setFillColor(style.backgroundColor);
    labelBody.setOutlineColor(style.outlineColor);
    labelBody.setOutlineThickness(style.borderThickness);

    labelText.setFont(*style.font);
    labelText.setFillColor(style.textColor);
    sf::FloatRect text_size = labelText.getGlobalBounds();
    labelBody.setSize(sf::Vector2f(100.0f, 50.0f));

}

Label::Label(Style s, std::string text){

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

void Label::setText(std::string text) {

    labelText.setString(text);
    sf::FloatRect text_size = labelText.getGlobalBounds();
    labelBody.setSize(sf::Vector2f(text_size.width+padding, text_size.height+padding));

}

void Label::setPadding(float p) {

    padding = p;
    sf::FloatRect text_size = labelText.getGlobalBounds();
    labelBody.setSize(sf::Vector2f(text_size.width+padding, text_size.height+padding));

}

void Label::draw(sf::RenderTarget &t, sf::RenderStates s) const {

    if (!visible) {
        return; // do nothing
    } 

    t.draw(labelBody);
    t.draw(labelText);

}