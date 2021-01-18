
#include "list.h"
#include <stdio.h>
#include "make_list.h"
#include "section.h"
#include "fgetl.h"
#include "strip.h"
#include "xmalloc.h"
#include "list_insert.h"
#include <stdlib.h>
#include "read_option.h"


list* read_cfg(char* filename)
{
    FILE* file = fopen(filename, "r");
    char* line;
    list* sections = make_list();
    section* current = 0;
    while ((line = fgetl(file)) != 0) {
        strip(line);
        switch (line[0]) {
        case '[':
            current = (section*)xmalloc(sizeof(section));
            list_insert(sections, current);
            current->options = make_list();
            current->type = line;
            break;
        case '\0':
            free(line);
            break;
        case '#':
            free(line);
            break;
        default:
            read_option(line, current->options);
            break;
        }
    }
    fclose(file);
    return sections;
}