#ifndef CLASHING_COUNTRIES_GAME_POWERUP_HPP
#define CLASHING_COUNTRIES_GAME_POWERUP_HPP

#include "entity.hpp"

namespace clashing_countries {
    namespace game {
        class power_up : public entity {
            public:
                int HP;
                virtual void Attack()=0;

        };
    }
}

#endif