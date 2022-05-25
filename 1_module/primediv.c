#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long n;
    scanf("%ld", &n);
    n = labs(n);
    int prime = 1;
    long d = 2;
    while (d * d <= n && prime) {
        prime = (n % d) != 0;
        d++;
    }
    if (prime) printf("%ld", n);
    else if ((n & (n - 1)) == 0) printf("%d", 2);
    else {
        long *primes = malloc(sizeof(long));
        int size = 0;
        d = 2;
        while (n > 1) {
            if (n % d == 0) {
                size++;
                primes = realloc(primes, size);
                primes[size - 1] = d;
                while (n % d == 0) n /= d;
            }
            d++;
        }
        printf("%ld", primes[size - 1]);
        free(primes);
    }
    return 0;
}

