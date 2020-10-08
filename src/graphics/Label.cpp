#include <clashingcountries/graphics.hpp>
#include <clashingcountries/graphics/BaseGui.hpp>
#include <clashingcountries/graphics/Label.hpp>

using namespace clashing_countries::graphics;

Label::Label() {

    style = Style(sf::Color(0,0,0,150), sf::Color(255,255,255,255), sf::Color(255,255,255,255), 10.0f);
    labelBody.setFillColor(style.backgroundColor);
    labelBody.setOutlineColor(style.outlineColor);
    labelBody.setOutlineThickness(style.borderThickness);

    labelText.setFont(*style.font);
    labelText.setFillColor(style.textColor);
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
    labelBody.setSize(sf::Vector2f(text_size.width+style.padding, text_size.height+style.padding));

}

void Label::setPadding(float p) {

    style.padding = p;
    sf::FloatRect text_size = labelText.getGlobalBounds();
    labelBody.setSize(sf::Vector2f(text_size.width+style.padding, text_size.height+style.padding));

}

void Label::setPosition(float x, float y) {

    labelBody.setPosition(x,y);
    labelText.setPosition(x,y);

}

void Label::setPosition(const sf::Vector2f& position) {

    labelBody.setPosition(position);
    labelText.setPosition(position);

}


sf::Vector2f Label::getPosition() const {
    return labelBody.getPosition();
}

sf::FloatRect Label::getGlobalBounds() const {

    return labelBody.getGlobalBounds();

}

void Label::MouseClickEvent() {
    // nothing
}

void Label::MouseHoverEvent() {
    // nothing
}

void Label::KeyboardEvent() {
    // nothing
}

void Label::draw(sf::RenderTarget &t, sf::RenderStates s) const {

   if (this->visible) {
        if (this->style.bodyVisible) {
            t.draw(labelBody);
        }
        if (this->style.outlineVisible) {
            t.draw(labelText);
        }   
    }

}