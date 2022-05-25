#include <stdio.h>

int main() {
    long a[8], b[8];
    for (int i = 0; i < 8; i++) scanf("%ld", &a[i]);
    for (int i = 0; i < 8; i++) scanf("%ld", &b[i]);
    long min = b[0];
    for (int i = 1; i < 8; i++) {
        if (b[i] < min) min = b[i];
    }
    int f = 1;
    for (int i = 0; i < 8; i++) {
        int p = 0;
        for (int j = 0; j < 8; j++) {
            if (b[j] == a[i]) {
                p = 1;
                b[j] = min - 1;
                break;
            }
        }
        if (p == 0) {
            f = 0;
            break;
        }
    }
    if (f == 1) puts("yes");
    else puts("no");
    return 0;
}