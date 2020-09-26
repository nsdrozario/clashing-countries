#ifndef CLASHING_COUNTRIES_CORE_UTIL_CONFIG_VARS_HPP
#define CLASHING_COUNTRIES_CORE_UTIL_CONFIG_VARS_HPP

#include <vector>
#include <string>
#include <map>

extern const std::vector<std::string> settings_ints;
extern const std::vector<std::string> settings_bools;
extern const std::vector<std::string> settings_strings;

extern std::map<std::string, int> int_settings;
extern std::map<std::string, bool> bool_settings;
extern std::map<std::string, std::string> string_settings;

#endif