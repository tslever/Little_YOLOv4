
#include "layer.h"


int entry_index(layer l, int batch, int location, int entry)
{
    int n = location / (l.w * l.h);
    int loc = location % (l.w * l.h);
    return batch * l.outputs + n * l.w * l.h * (4 + l.classes + 1) + entry * l.w * l.h + loc;
}