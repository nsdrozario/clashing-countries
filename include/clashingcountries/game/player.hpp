#ifndef CLASHING_COUNTRIES_GAME_PLAYER_HPP
#define CLASHING_COUNTRIES_GAME_PLAYER_HPP

#include <vector>
#include <string>
#include "power_up.hpp"

namespace clashing_countries {
    namespace game {
        class player : public entity {
            public:

                // constructors
                player();
                player(std::string new_name, int new_hp=100, int new_defense=0, int new_mana=0);

                // setters
                void set_defense(int d);
                void set_mana(int m);

                // getters
                int get_defense();
                int get_mana();

                // operations
                // void Attack(Entity e)
                //virtual std::string serialize();

            private:
                int mana;
                int defense;
                int score = 0;
                std::vector<power_up> powers;
        };
    }
}

#endif