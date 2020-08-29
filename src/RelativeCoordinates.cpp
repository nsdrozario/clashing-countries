#include <clashingcountries/graphics.hpp>
using namespace clc_ui;

RelativeCoordinates::RelativeCoordinates() {

    x = 0.0f;
    y = 0.0f;

}

RelativeCoordinates::RelativeCoordinates(float x, float y) {

    this->x = x;
    this->y = y;

}

sf::Vector2f RelativeCoordinates::getVector() const {
    
    sf::Vector2u screen_size = renderTarget.getSize();
    float real_x = static_cast<float>(screen_size.x) * this->x;
    float real_y = static_cast<float>(screen_size.y) * this->y;
    return sf::Vector2f(real_x, real_y);

}