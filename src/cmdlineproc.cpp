#include <clashingcountries/cmdlineproc.hpp>

void init_args(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        
        char *current_arg;
        char *next_arg;

        current_arg = argv[i];

        if (current_arg[0] == '-') {
                
            // check if option requires an argument
            // if not just put it in the args vector
       }
       
    }

}