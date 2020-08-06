#ifndef CLC_CMDLINEPROC_HPP
#define CLC_CMDLINEPROC_HPP

#include <map>
#include <vector>
#include <string>

namespace clc_cmdlineproc {

    static class cmd_args {
        public:
            std::map<std::string, std::string> options;
            std::vector<std::string> args;
    };

    // functions to process command line arguments or something
    void init_args(int argc, char *argv[]);

}

#endif