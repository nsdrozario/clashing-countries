#include <iostream>
#include <thread>
#include <queue>
#include <cmdlineproc.hpp>
// #include <clashingcountries.hpp>
#include <clashingcountries/graphics.hpp>
#include <clashingcountries/extend_script.hpp>

// global vars 
sf::RenderWindow renderTarget;
std::vector<clc_ui::BaseGui *> RenderQueue; // probably going to change this to use smart pointers later

void lua_thread() {
    /*
    sol::state l;
    
    // importing classes into lua
    
    // Entity class
    sol::constructors<clashing_countries::Entity()> entity_constructors();
    sol::usertype<clashing_countries::Entity> entity = l.new_usertype<clashing_countries::Entity>("Entity", entity_constructors);
    entity["HP"] = &clashing_countries::Entity::HP;
    entity["Attack"] = &clashing_countries::Entity::Attack;
    
    // Player class
    sol::constructors<clashing_countries::Player> player_constructors();
    sol::usertype<clashing_countries::Player> player = l.new_usertype<clashing_countries::Player>("Player", player_constructors);
    player["HP"] = &clashing_countries::Player::HP;
    player["Attack"] = &clashing_countries::Player::Attack;
    player["Mana"] = &clashing_countries::Player::Mana;
    player["Defense"] = &clashing_countries::Player::Defense;
    // I don't want to register the vector of powerups yet I haven't read enough documentation to confirm that's how it works
    */
}

void render() {

    for (clc_ui::BaseGui *g : RenderQueue) {
        renderTarget.draw(*g);
    }

}

int main () { // main thread

    cmdlineproc::cmd_args c;
    c.set_flag("--no-gui");
    
    load_config(); // load config file
    
    if (std::find(c.flags.begin(), c.flags.end(), std::string("--no-gui")) != c.flags.end() ) {

        std::cout << "Clashing Countries" << std::endl;    
        exit(0);
        
    } else {
    
        if (bool_settings["fullscreen"]) {
            
            // get display resolution
            renderTarget.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Clashing Countries", sf::Style::Fullscreen);

        } else {
    
            // use set resolution
            renderTarget.create(sf::VideoMode(int_settings["screen_width"], int_settings["screen_height"]), "Clashing Countries", sf::Style::Default);

        }

    }

    if (!init_font()) { // load font
        std::cerr << "error opening font" << std::endl;
    }

    clc_ui::Style s(&text_font, sf::Color(50,50,50,255), sf::Color(150,200,255,255));
    clc_ui::Label label(s, "Clashing Countries");
    clc_ui::Button b;
    b.setPosition(clc_ui::RelativeCoordinates(0.5, 0.5));
    b.setText("Start");
    label.setPadding(10.0f);

    while (renderTarget.isOpen()) {

        sf::Event e;
        
        while (renderTarget.pollEvent(e)) {

            if (e.type == sf::Event::Closed) {

                renderTarget.close();
            
            } else if (e.type == sf::Event::MouseButtonPressed) {



            } else if (e.type == sf::Event::KeyPressed) {


            }

            renderTarget.clear(sf::Color::Black);

            renderTarget.draw(label); 
            renderTarget.draw(b);

            renderTarget.display();

        }

    }

    return 0;

}
