#include <stdlib.h>


void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j)) {
    int n = 2, a = 1, b = 2;
    while (a + b < nel) {
        int tmp = b;
        b = a + b;
        a = tmp;
        n++;
    }
    int *fib = malloc(n * sizeof(int));
    fib[0] = 1, fib[1] = 2;
    for (int i = 2; i < n; i++) fib[i] = fib[i - 1] + fib[i - 2];
    for (int k = n - 1; k >= 0; k--) {
        int d = fib[k];
        for (int i = d; i < nel; i++) {
            int j = i;
            while (j >= d && compare(j - d, j) == 1) {
                swap(j, j - d);
                j -= d;
            }
        }
    }
    free(fib);
}