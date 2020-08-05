#include <clashingcountries/extend_script.hpp>
#include <clashingcountries/configuration.hpp>
#include <iostream>

void init_lua_config() {

    lua_State *l_state = luaL_newstate(); // create lua state

    // no libraries have been loaded so no functions should be runnable within the config.lua script
    
    if(luaL_dofile(l_state, CLC_CONFIG_FILE_PATH)) { // open and run lua file and check for errors
    
        std::cerr << "error loading configuration file" << std::endl;
        return;
    
    }

    for (std::string s : settings_ints) { // get all integer config values

        lua_getglobal(l_state, s.c_str());
        int var = lua_tointeger(l_state, -1);
        int_settings[s] = var;

    }

    for (std::string s : settings_bools) { // get all boolean config values

        lua_getglobal(l_state, s.c_str());
        bool var = lua_toboolean(l_state, -1);
        bool_settings[s] = var;

    }

    for (std::string s : settings_strings) { // get all string config values

        lua_getglobal(l_state, s.c_str());
        std::string var (lua_tostring(l_state, -1));
        string_settings[s] = var;

    }

    lua_close(l_state); // close lua state
    return; 
    
}