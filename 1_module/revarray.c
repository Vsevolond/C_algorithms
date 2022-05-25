#include <string.h>
#include <stdlib.h>

void revarray(char *base, size_t nel, size_t width) {
    char *t = malloc(width);
    for (char *i = base, *j = base + (nel - 1) * width; i < j; i += width, j -= width) {
        memcpy(t, i, width);
        memcpy(i, j, width);
        memcpy(j, t, width);
    }
    free(t);
}
