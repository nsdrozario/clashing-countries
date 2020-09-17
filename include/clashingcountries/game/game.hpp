#ifndef CLASHING_COUNTRIES_GAME_GAME_HPP
#define CLASHING_COUNTRIES_GAME_GAME_HPP

#include "player.hpp"
#include <vector>

namespace clashing_countries {
    namespace game {
        class game {
            public:
                static std::vector<player> players;
        };
    }
}

#endif