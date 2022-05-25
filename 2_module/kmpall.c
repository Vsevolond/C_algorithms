#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int *pref_func (char *s, int n) {
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

char* concat(char *s1, int len1, char *s2, int len2) {
    int len = len1 + len2 + 1;
    char *result = malloc(len);
    memcpy(result, s1, len1);
    char op[2] = {'#', '\0'};
    memcpy(result + len1, op, 1);
    memcpy(result + len1 + 1, s2, len2);
    return result;
}

int main(int argc, char **argv) {
    char *s = argv[1];
    char *t = argv[2];
    int len_s = strlen(s);
    int len_t = strlen(t);
    scanf("%s", s);
    scanf("%s", t);
    char *str = concat(s, len_s, t, len_t);
    int n = len_s + len_t + 1;
    int *pref = pref_func(str, n);
    for (int i = len_s + 1; i < n; i++) {
        if (pref[i] == len_s) printf("%d ", i - 2 * len_s);
    }
    free(pref);
    free(str);
    return 0;
}