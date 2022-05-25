#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ul unsigned long

int main() {
    ul x;
    scanf("%lu", &x);
    ul a = 1, b = 2;
    int n = 2;
    while (a + b <= x) {
        ul tmp = b;
        b = a + b;
        a = tmp;
        n++;
    }
    if (x == 0) printf("%d", 0);
    else if (x == 1) printf("%d", 1);
    else if (x == 2) printf("%d", 10);
    else {
        char *fib = malloc((n + 1) * sizeof(char));
        memset(fib, '0', n);
        for (int i = 0; i < n; i++) {
            if (b <= x) {
                fib[i] = '1';
                x -= b;
            }
            ul tmp = b - a;
            b = a;
            a = tmp;
        }
        fib[n] = '\0';
        printf("%s", fib);
        free(fib);
    }
    return 0;
}

