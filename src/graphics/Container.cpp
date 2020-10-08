#include <clashingcountries/graphics.hpp>
using namespace clashing_countries::graphics;

bool ZIndexSort::operator() (const BaseGui *g1, const BaseGui *g2) const {
    return g1->zIndex > g2->zIndex;
}

Container::Container() {

    this->style = Style(sf::Color::Black, sf::Color::White, sf::Color::White);
    this->containerBody.setFillColor(this->style.backgroundColor);
    this->containerBody.setOutlineColor(this->style.outlineColor);
    this->containerBody.setOutlineThickness(this->style.borderThickness);

}

void Container::MouseClickEvent() {

    /*
    
        We are iterating over all the contents of the container
        instead of simply pushing all our elements into RenderQueue because
        it'd be a nightmare to figure out which element belongs where and
        to handle dynamic UI, especially since we plan on generating UI at runtime
        using Lua scripts and potentially JSON.

    */

    sf::Vector2i mouse_coords = sf::Mouse::getPosition();

    for (BaseGui *element : this->contents) {

        sf::FloatRect element_bounding_box = element->getGlobalBounds();
        if ( element_bounding_box.contains(util::renderTarget.mapPixelToCoords(mouse_coords)) ) {

            element->MouseClickEvent();

        }

    }

    
}

void Container::MouseHoverEvent() {

    sf::Vector2i mouse_coords = sf::Mouse::getPosition();

    for (BaseGui *element : this->contents) {

        sf::FloatRect element_bounding_box = element->getGlobalBounds();
        if ( element_bounding_box.contains(util::renderTarget.mapPixelToCoords(mouse_coords)) ) {

            element->MouseHoverEvent();

        }

    }

}

void Container::KeyboardEvent() {

    // nothing (the focus will be on the element selected, Container does not need to do anything here)

}

sf::FloatRect Container::getGlobalBounds() const {

    return this->containerBody.getGlobalBounds(); // now we need to figure out how resizing works when elements eventually overflow

}

sf::Vector2f Container::getPosition() const {

    return this->containerBody.getPosition();

}

void Container::setPosition(const float x, const float y) {

    // oh dear we will have to recalc EVERYTHING here

    containerBody.setPosition(x,y);
    // for (BaseGui *g : this->contents) {

        //  g->setPosition(g->relativePosition);
        // commented out because it will induce build errors at the moment

    // }

}

void Container::setPosition(const sf::Vector2f &position) {

    containerBody.setPosition(position);
    // for (BaseGui *g : this->contents) {

        //  g->setPosition(g->relativePosition);
        // commented out because it will induce build errors at the moment

    // }

}

void Container::draw(sf::RenderTarget &t, sf::RenderStates s) const {

    t.draw(this->containerBody);

    for (BaseGui *g : this->contents) {
        t.draw(*g);
    }       

}