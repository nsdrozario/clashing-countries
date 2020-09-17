#ifndef CLASHING_COUNTRIES_GAME_ENTITY_HPP
#define CLASHING_COUNTRIES_GAME_ENTITY_HPP

namespace clashing_countries {
    namespace game {
        class entity {
            public:
                int HP;
                virtual void Attack()=0;

        };
    }
}

#endif