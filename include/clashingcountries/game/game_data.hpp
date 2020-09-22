#ifndef CLASHING_COUNTRIES_GAME_GAME_HPP
#define CLASHING_COUNTRIES_GAME_GAME_HPP

#include "player.hpp"
#include <vector>
#include <string>

namespace clashing_countries {
    namespace game {
        class game_data {
            public:
                static std::vector<player> players;
                static int ranks;

                static void save_to_file(std::string file_path);
                static void load_from_file(std::string file_path);

        };
    }
}

#endif