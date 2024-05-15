
#include <string.h>
#include <stdlib.h>


float find_float_arg(int argc, char** argv, char* arg, float def)
{
    // For each argument in main's argument vector...
    for (int i = 0; i < argc - 1; ++i) {

        // If the present argument in main's argument vector
        // is equivalent to string arg (e.g., "-thresh"), then
        // convert the argument immediately after the present argument
        // to a floating point number, and return that number.
        if (strcmp(argv[i], arg) == 0) {
            return atof(argv[i + 1]);
        }
    }

    // If no argument in main's argument vector was equivalent to string arg, then
    // return the default floating point number def (e.g., 0.25).
    return def;
}