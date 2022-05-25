#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int compare (void * a, void * b)
{
    return ( *(int*)a - *(int*)b );
}*/


int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)) {
    int m = 0;
    void *max = malloc(width);
    memcpy(max, base, width);
    char *el = (char*)base;
    for (size_t i = 0; i != nel; i++) {
        if (compare(el, max) > 0) {
            m = (int)i;
            memcpy(max, el, width);
        }
        el += width;
    }
    free(max);
    return m;
}

/*int main() {
    int a[5] = {1, 342, 32, 32, 4};
    printf("%d", maxarray(a, 5, sizeof(a[0]), compare));
    return 0;
}*/

