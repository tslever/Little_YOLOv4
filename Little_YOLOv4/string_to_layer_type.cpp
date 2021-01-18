
#include "LAYER_TYPE.h"
#include <string.h>


LAYER_TYPE string_to_layer_type(char* type)
{
    if (strcmp(type, "[shortcut]") == 0) return SHORTCUT;
    if (strcmp(type, "[yolo]") == 0) return YOLO;
    if (strcmp(type, "[conv]") == 0 || strcmp(type, "[convolutional]") == 0) return CONVOLUTIONAL;
    if (strcmp(type, "[max]") == 0 || strcmp(type, "[maxpool]") == 0) return MAXPOOL;
    if (strcmp(type, "[route]") == 0) return ROUTE;
    if (strcmp(type, "[upsample]") == 0) return UPSAMPLE;
}