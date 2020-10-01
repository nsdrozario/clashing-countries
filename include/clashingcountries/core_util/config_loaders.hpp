#ifndef CLASHING_COUNTRIES_CORE_UTIL_CONFIG_LOADERS 
#define CLASHING_COUNTRIES_CORE_UTIL_CONFIG_LOADERS

#define SOL_ALL_SAFETIES_ON_1

#include <string>
#include <exception>
#include <sol/sol.hpp>

namespace clashing_countries {

    namespace core_utils {

        void load_config(std::string file_path);

    }

}

#endif