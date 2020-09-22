#include <clashingcountries/game/player.hpp>
using namespace clashing_countries::game;

player::player() {

    this->hp = 100;
    this->defense = 0;
    this->name = "Default";

    this->export_data["hp"] = this->hp;
    this->export_data["defense"] = this->defense;
    this->export_data["mana"] = this->mana;
    this->export_data["name"] = this->name;    

}

player::player(std::string new_name, int new_hp, int new_defense, int new_mana) {

    this->hp = new_hp;
    this->defense = new_defense;
    this->mana = new_mana;
    this->name = new_name;

    this->export_data["hp"] = this->hp;
    this->export_data["defense"] = this->defense;
    this->export_data["mana"] = this->mana;
    this->export_data["name"] = this->name;   

}