#ifndef CLASHINGCOUNTRIES_HPP
#define CLASHINGCOUNTRIES_HPP

#include <vector>

namespace clashing_countries {
    
    class Game {

        public:
            static std::vector<Player> players; 
            
    };

    class Entity {

        public:
            int HP;

            virtual void Attack()=0;

    };

    class Player : public Entity {

        public:
            int Mana;
            int Defense;




    };

    class Powerup : public Entity {

        public:
            

    };

}

#endif