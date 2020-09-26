#include <clashingcountries/core_util.hpp>
#include <clashingcountries/graphics.hpp>
#include <clashingcountries/client/client_main.hpp>
using namespace clashing_countries;

std::thread game_thread;
std::thread file_thread;

int main (int argc, char *argv[]) {

    // test

    graphics::util::init_font();

    /*
    try {
        core_utils::load_config(CLC_CONFIG_FILE_PATH);
    } catch (std::exception e) {
        std::cerr << "Could not load configuration file, please check that all properties are defined" << std::endl;
        exit(-1);
    }
    */

    std::cout << "Successful, exiting..." << std::endl;

    return 0;

}