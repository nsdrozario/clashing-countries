#ifndef CLC_CONFIGURATION_HPP
#define CLC_CONFIGURATION_HPP

#include <map>
#include <vector>
#include <string>

std::vector<std::string> video_settings_keys {
    "screen_width",
    "screen_height",
};

std::map<std::string, int> video_settings;

#endif