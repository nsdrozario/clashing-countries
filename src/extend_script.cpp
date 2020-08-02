#include <clashingcountries/extend_script.hpp>
#include <clashingcountries/configuration.hpp>


lua_State **init_lua_config() {

    lua_State *l = luaL_newstate();
    luaL_loadfile(l, CLC_CONFIG_FILE_PATH);
    for (std::string s : video_settings_keys) {
        lua_getglobal(l, s.c_str());
        video_settings.insert(make_pair(s, (int)lua_tonumber(l, -1)));
    }

    return &l;

}