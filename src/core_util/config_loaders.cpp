#include <clashingcountries/core_util/config_loaders.hpp>
#include <clashingcountries/core_util/config_vars.hpp>
#include <iostream>

using namespace clashing_countries;

void core_utils::load_config(std::string file_path) {

    sol::state l;
    l.script_file(file_path); // no libraries have been loaded because we only want to read some variables

    for (std::string s : settings_ints) {
        int_settings[s] = l.get<int>(s);
    }

    for (std::string s : settings_bools) {
        bool_settings[s] = l.get<bool>(s);
    }

    for (std::string s : settings_strings) {
        string_settings[s] = l.get<std::string>(s);
    }

}


