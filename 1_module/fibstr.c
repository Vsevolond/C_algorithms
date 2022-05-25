#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibstr(int n) {
    char *sa = malloc(2);
    char *sb = malloc(2);
    memcpy(sa, "a", 1);
    memcpy(sb, "b", 1);
    sa[1] = '\0';
    sb[1] = '\0';
    if (n == 1) {
        free(sb);
        return sa;
    }
    else if (n == 2) {
        free(sa);
        return sb;
    }
    else {
        int a = 1, b = 2;
        for (int i = 2; i < n; i++) {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        sa = realloc(sa, a + 1);
        sb = realloc(sb, b + 1);
        memcpy(sa, "a", 1);
        memcpy(sb, "b", 1);
        a = 1, b = 2;
        for (int i = 2; i < n; i++) {
            char *tmp = malloc(b  + 1);
            memcpy(tmp, sb, b + 1);
            tmp[b] = '\0';
            int t = b;
            memcpy(sb, sa, a + 1);
            memcpy(sb + strlen(sb), tmp, t + 1);
            b = a + b;
            sb[b] = '\0';
            memcpy(sa, tmp, t + 1);
            sa[t] = '\0';
            a = t;
            free(tmp);
        }
        free(sa);
        return sb;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    char *res = fibstr(n);
    printf("%s", res);
    free(res);
    return 0;
}

