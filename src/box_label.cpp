#include <clashingcountries/graphics.hpp>
using namespace clc_ui;

void box_label::render() {

    // first update parameters
    body.setFillColor(bg_color);
    body.setOutlineColor(outline_color);
    body.setPosition(xpos, ypos);
    body.setScale(x_size, y_size);


    // now actually draw

}