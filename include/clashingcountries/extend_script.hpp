#ifndef CLC_EXTEND_SCRIPT_HPP
#define CLC_EXTEND_SCRIPT_HPP

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

#include <clashingcountries/configuration.hpp>

void init_lua_config(); // loads config.lua

#endif