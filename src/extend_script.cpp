#include <clashingcountries/extend_script.hpp>
#include <clashingcountries/configuration.hpp>
#include <iostream>

void init_lua_config() {

    lua_State *l_state = luaL_newstate();
    
    if(luaL_dofile(l_state, CLC_CONFIG_FILE_PATH)) {
    
        std::cerr << "error loading configuration file" << std::endl;
        return;
    
    }

    for (std::string s : video_settings_keys) {

        lua_getglobal(l_state, s.c_str());
        int var = lua_tointeger(l_state, -1);
        video_settings[s] = var;

    }

}