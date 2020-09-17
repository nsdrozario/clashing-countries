#include <clashingcountries/core_util/config_vars.hpp>

const std::vector<std::string> settings_ints {
    "screen_width",
    "screen_height"
};

const std::vector<std::string> settings_bools {
    "fullscreen"
};

const std::vector<std::string> settings_strings {
    
};

std::map<std::string, int> int_settings;
std::map<std::string, bool> bool_settings;
std::map<std::string, std::string> string_settings;