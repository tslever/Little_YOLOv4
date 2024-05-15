
#include "list.h"
#include "get_paths.h"
#include "list_to_array.h"
#include "free_list.h"


char** get_labels_custom(char* filename)
{
    list* plist = get_paths(filename);
    char** labels = (char**)list_to_array(plist);
    free_list(plist);
    return labels;
}