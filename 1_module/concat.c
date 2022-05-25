#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *concat(char **s, int n) {
    char *res = malloc((n * 1000 + 1) * sizeof(char));
    int len = 0;
    for (int i = 0; i < n; i++) {
        memcpy(res + len, s[i], strlen(s[i]) + 1);
        len += (int)strlen(s[i]);
    }
    res[len] = '\0';
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    char *s[n];
    for (int i = 0; i < n; i++) {
        s[i] = malloc(1000 * sizeof(char));
        scanf("%s", s[i]);
    }
    char *res = concat(s, n);
    printf("%s", res);
    free(res);
    for (int i = 0; i < n; i++) free(s[i]);
    return 0;
}

