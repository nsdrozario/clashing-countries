#ifndef CLASHINGCOUNTRIES_HPP
#define CLASHINGCOUNTRIES_HPP

#include <vector>
#include <string>

namespace clashing_countries {
    
    

    class Entity {

        public:
            int HP;

            virtual void Attack()=0;

    };

    class Player : public Entity {

        public:
            int Mana;
            int Defense;
            std::string name;
        
            // void Attack(Entity e);
            std::vector<Powerup> powers;
        
    };

    class Powerup : public Entity {

        public:
                

    };

    class Game {

        public:
            static std::vector<Player> players; 
            
    };
}

#endif
