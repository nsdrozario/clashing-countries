#include <clashingcountries/graphics.hpp>
using namespace clashing_countries::graphics;

bool ZIndexSort::operator() (const BaseGui *g1, const BaseGui *g2) {
    return g1->zIndex > g2->zIndex;
}



void Container::draw(sf::RenderTarget &t, sf::RenderStates s) const {

    t.draw(containerBody);

    for (BaseGui *g : contents) {
        t.draw(*g);
    }       

}