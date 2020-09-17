#ifndef CLASHING_COUNTRIES_GAME_PLAYER_HPP
#define CLASHING_COUNTRIES_GAME_PLAYER_HPP

#include <vector>
#include <string>
#include "power_up.hpp"

namespace clashing_countries {
    namespace game {
        class player : public entity {

            public:
                int mana;
                int defense;
                std::string name;

                int score;

                // void Attack(Entity e);
                std::vector<power_up> powers;
        };
    }
}

#endif