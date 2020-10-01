#include <clashingcountries/graphics.hpp>

using namespace clashing_countries::graphics;

BaseGui::BaseGui() {

    style = Style();

}

void BaseGui::setParent(BaseGui *g) {
    this->parent = g;
}

BaseGui *BaseGui::getParent() const {
    return this->parent;
}

void BaseGui::setPosition(const RelativeCoordinates &position) {

    this->relativePosition = position;

    if (this->parent == nullptr) {
        sf::Vector2u screen_size = graphics::util::renderTarget.getSize();
        float screen_x = static_cast<float> (screen_size.x);
        float screen_y = static_cast<float> (screen_size.y);
        this->setPosition(screen_x * position.x, screen_y * position.y);
    } else {
        sf::FloatRect bounding_box = this->parent->getGlobalBounds();
        float origin_x = bounding_box.left;
        float origin_y = bounding_box.top;
        this->setPosition(
            origin_x + (position.x * (bounding_box.width - origin_x)), 
            origin_y + (position.y * (bounding_box.height - origin_y))
        );
    }
    
}

