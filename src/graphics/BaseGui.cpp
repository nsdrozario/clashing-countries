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


