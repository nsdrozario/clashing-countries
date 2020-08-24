#include <clashingcountries/graphics.hpp>
using namespace clc_ui;

Label::Label(Style s, std::string text){

    style = s;

    labelBody.setFillColor(s.backgroundColor);
    labelBody.setOutlineColor(s.outlineColor);
    labelBody.setOutlineThickness(s.borderThickness);

    labelText.setFont(*s.font);
    labelText.setString(text);
    labelText.setFillColor(s.textColor);

}

void Label::draw(sf::RenderTarget &t, sf::RenderStates s) const {

    if (!visible) {
        return; // do nothing
    } 

    t.draw(labelBody);
    t.draw(labelText);

}