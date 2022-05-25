#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void pref_func (char *s, int n, int *pi) {
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}

void concat(char *s1, int len1, char *s2, int len2, char *result) {
    memcpy(result, s1, len1);
    char split[2] = {'#', '\0'};
    memcpy(result + len1, split, 1);
    memcpy(result + len1 + 1, s2, len2);
}

int main(int argc, char **argv) {
    char *s = argv[1];
    char *t = argv[2];
    int len_s = strlen(s);
    int len_t = strlen(t);
    scanf("%s", s);
    scanf("%s", t);
    char *str = malloc(len_s + len_t + 1);
    concat(s, len_s, t, len_t, str);
    int n = len_s + len_t + 1;
    int *pref = malloc(n * sizeof(int));
    memset(pref, 0, n * sizeof(int));
    pref_func(str, n, pref);
    for (int i = len_s + 1; i < n; i++) {
        if (pref[i] == 0) {
            printf("%s\n", "no");
            free(str);
            free(pref);
            return 0;
        }
    }
    printf("%s\n", "yes");
    free(str);
    free(pref);
    return 0;
}