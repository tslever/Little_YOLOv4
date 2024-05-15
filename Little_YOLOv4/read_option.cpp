
#include "list.h"
#include <string.h>
#include "option_insert.h"


int read_option(char* s, list* options)
{
    size_t i;
    size_t len = strlen(s);
    char* val = 0;
    for (i = 0; i < len; ++i) {
        if (s[i] == '=') {
            s[i] = '\0';
            val = s + i + 1;
            break;
        }
    }
    char* key = s;
    option_insert(options, key, val);
    return 1;
}