#include <clashingcountries.hpp>
#include <clashingcountries/graphics.hpp>
#include <clashingcountries/extend_script.hpp>

int main () {

    init_lua_config();

    std::cout << video_settings["screen_width"] << std::endl;

    return 0;

}