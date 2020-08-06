#include <clashingcountries/graphics.hpp>
#include <clashingcountries/configuration.hpp>

using namespace clc_ui;

// implementation of clc_ui::compound_ui_element methods

void compound_ui_element::setXPosAbsolute(float x) {
    xpos = x;
}
void compound_ui_element::setXPosCenter(float x) {
    xpos = x-(x_size/2.0f);
}  

void compound_ui_element::setYPosAbsolute(float y) {
    ypos = y; 
}

void compound_ui_element::setYPosCenter(float y) {
    ypos = y-(y_size/2.0f);
}
void compound_ui_element::setXSize(float x) {
    x_size = x;
}
void compound_ui_element::setYSize(float y) {
    y_size = y;
}
void compound_ui_element::setBackgroundColor(sf::Color c) {
    bg_color = c;
}
void compound_ui_element::setOutlineColor(sf::Color c) {
    outline_color = c;
}
void compound_ui_element::setOutlineThickness(float x) {
    outline_thickness = x;
}