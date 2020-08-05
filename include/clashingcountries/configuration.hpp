#ifndef CLC_CONFIGURATION_HPP
#define CLC_CONFIGURATION_HPP

#define CLC_CONFIG_FILE_PATH "config.lua"

#include <map>
#include <vector>
#include <string>

// keys for config variables
extern const std::vector<std::string> settings_ints;
extern const std::vector<std::string> settings_bools;
extern const std::vector<std::string> settings_strings;

// where config variables are stored in key-value pairs via maps
extern std::map<std::string, int> int_settings;
extern std::map<std::string, bool> bool_settings;
extern std::map<std::string, std::string> string_settings;

#endif