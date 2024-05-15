
#include <string.h>


void strip(char* s)
{
    size_t len = strlen(s);
    size_t offset = 0;
    char c;
    for (int i = 0; i < len; ++i) {
        c = s[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') ++offset;
        else s[i - offset] = c;
    }
    s[len - offset] = '\0';
}