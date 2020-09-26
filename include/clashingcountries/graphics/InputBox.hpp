#ifndef CLASHING_COUNTRIES_GRAPHICS_INPUTBOX_HPP
#define CLASHING_COUNTRIES_GRAPHICS_INPUTBOX_HPP

#include "BaseGui.hpp"
#include "Label.hpp"

namespace clashing_countries {

    namespace graphics {

        class InputBox : public Label, public BaseGui {

            public:

                std::string real_input; // visible input will be the default labeltext's text

                virtual void KeyboardEvent();
                virtual void ClickEvent();

        };

    }

}

#endif