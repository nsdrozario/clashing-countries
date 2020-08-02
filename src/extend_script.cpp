#include <clashingcountries/extend_script.hpp>
#include <clashingcountries/configuration.hpp>


lua_State **init_lua_config() {

    lua_State *l = luaL_newstate();
    
    for (std::string s : video_settings_keys) {
        
    }

    return &l;

}