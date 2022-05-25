#include <stdio.h>

int main() {
    long x, n, c;
    scanf("%ld%ld", &n, &x);
    c = n;
    long a[n + 1];
    for (long i = 0; i < n + 1; i++) scanf("%ld", &a[i]);
    long long f = a[0], p = a[0] * c;
    c--;
    for (long i = 1; i < n + 1; i++) f = f * x + a[i];
    for (long i = 1; i < n; i++) {
        p = p * x + a[i] * c;
        c--;
    }
    printf("%lld\n", f);
    printf("%lld\n", p);
    return 0;
}