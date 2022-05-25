#include <stdio.h>

unsigned long long multimod(unsigned long long a, unsigned long long b, unsigned long long mod) {
    return ((a % mod) * (b % mod)) % mod;
}

unsigned long long summod(unsigned long long a, unsigned long long b, unsigned long long mod) {
    return ((a % mod) + (b % mod)) % mod;
}

unsigned long long f(unsigned long long a, unsigned long long b, unsigned long long mod) {
    if (b == 0) return 0;
    else return summod(2 * f(a, b >> 1, mod), multimod(a, b & 1, mod), mod);
}

int main() {
    unsigned long long a, b, m;
    scanf("%llu%llu%llu", &a, &b, &m);
    printf("%llu", f(a, b, m));
    return 0;
}