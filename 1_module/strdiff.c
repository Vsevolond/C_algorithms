#include <string.h>

int count (char *a, char *b) {
    int n = (int)strlen(a);
    int m = (int)strlen(b);
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            int first = (int)a[i];
            int second = (int)b[i];
            for  (int j = 0; j < 8; j++) {
                if ((first & 1) != (second & 1)) {
                    k += j;
                    return k;
                } else {
                    first = first >> 1;
                    second = second >> 1;
                }
            }
        } else k += 8;
    }
    for (int i = n; i < m; i++) {
        int symb = (int)b[i];
        for (int j = 0; j < 8; j++) {
            if ((symb & 1) != 0) {
                k += j;
                return k;
            } else symb = symb >> 1;
        }
    }
}

int strdiff (char *a, char *b) {
    if (!strcmp(a, b)) return -1;
    else {
        if (strlen(a) < strlen(b)) {
            return count(a, b);
        } else {
            return count(b, a);
        }
    }
}

