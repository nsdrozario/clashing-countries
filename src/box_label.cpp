#include <clashingcountries/graphics.hpp>
using namespace clc_ui;

void box_label::setTextColor(sf::Color c) {
    text_color = c;
}

void box_label::setTextSize(int x) {
    text_size = x;
}  

void box_label::setLabelText(std::string text) {
    label.setString(text);
}

void box_label::render(sf::RenderWindow& w) {

    // first update parameters
    body.setFillColor(bg_color);
    body.setOutlineColor(outline_color);
    body.setPosition(xpos, ypos);
    body.setScale(x_size, y_size);
    body.setOutlineThickness(outline_thickness);   

    label.setFont(text_font);
    label.setColor(text_color);
    label.setCharacterSize(text_size);
    label.setPosition(xpos, ypos);
    // now actually draw

    w.draw(body);
    w.draw(label);

}