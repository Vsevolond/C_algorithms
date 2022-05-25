#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        while (a >= b)
            a -= b;
        if (!a)
            return b;
        do {
            b -= a;
        } while (b >= a);
    }
    return a;
}

int *pref_func(char *s) {
    int n = (int)strlen(s);
    int *pi = malloc(n * sizeof(int));
    memset(pi, 0, n * sizeof(int));
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(int argc, char **argv) {
    char *str = argv[1];
    int *pref = pref_func(str);
    for (int i = 0; i < (int)strlen(str); i++) {
        if (pref[i] && gcd(i + 1, pref[i])) {
            int k = pref[i];
            while (pref[k - 1]) k = pref[k - 1];
            int f = 1;
            for (int j = k; j < i; j++) {
                if (pref[j] == 0) {
                    f = 0;
                    break;
                }
            }
            if ((i + 1) % k == 0 && f) printf("%d %d\n", i + 1, (i + 1) / k);
        }
    }
    free(pref);
    return 0;
}