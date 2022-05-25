#include <stdio.h>

int main() {
    int na, nb, a = 0, b = 0;
    scanf("%d", &na);
    if (na == 0) return 0;
    for (int i = 0; i < na; i++) {
        int c;
        scanf("%d", &c);
        a |= (1 << c);
    }
    scanf("%d", &nb);
    if (nb == 0) return 0;
    for (int i = 0; i < nb; i++) {
        int c;
        scanf("%d", &c);
        b |= (1 << c);
    }
    int m = a & b;
    for (int i = 0; i < 32; i++) {
        if (m & (1 << i)) printf("%d ", i);
    }
    return 0;
}