#ifndef CLASHING_COUNTRIES_GAME_ENTITY_HPP
#define CLASHING_COUNTRIES_GAME_ENTITY_HPP

#include <nlohmann/json.hpp>

namespace clashing_countries {
    namespace game {
        class entity {
            public:
                // constructors
                entity();
                entity(std::string new_name, int init_hp=100);
                
                // getters
                int get_hp();
                std::string get_name();

                // setters
                void set_hp(int new_hp);
                void set_name(std::string new_name);

                // overloadable 
                // virtual void attack()=0;
                // virtual std::string serialize()=0;

            protected:
                int hp;
                std::string name;
                nlohmann::json export_data;
        };
    }
}

#endif