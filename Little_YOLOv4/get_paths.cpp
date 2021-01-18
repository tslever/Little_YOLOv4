
#include "list.h"
#include <stdio.h>
#include "make_list.h"
#include "fgetl.h"
#include "strip.h"
#include "list_insert.h"
#include <stdlib.h>


list* get_paths(char* filename)
{
    char* path;
    FILE* file = fopen(filename, "r");
    list* lines = make_list();
    while ((path = fgetl(file))) {
        strip(path);
        list_insert(lines, path);
    }
    fclose(file);
    return lines;
}