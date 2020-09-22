#include <clashingcountries/game/entity.hpp>
using namespace clashing_countries::game;

entity::entity() {

    this->hp = 100;
    this->name = "Default";

    this->export_data["hp"] = this->hp;
    this->export_data["name"] = this->name;

}

entity::entity(std::string new_name, int init_hp) {

    this->hp = init_hp;
    this->name = new_name;

    this->export_data["hp"] = this->hp;
    this->export_data["name"] = this->name;

}

void entity::set_name(std::string new_name) {

    this->name = new_name;
    this->export_data["name"] = new_name; 

}

void entity::set_hp(int new_hp) {

    this->hp = new_hp;
    this->export_data["hp"] = new_hp;

}