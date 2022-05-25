#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 100

int overlap(char *s1, char *s2) {
    int lap = 0;

    char *suffix = (char *) malloc(max_len * sizeof(char));
    char *prefix = (char *) malloc(max_len * sizeof(char));

    for (int i = strlen(s1) - 1, j = 1; i > 0 && j < strlen(s2); i--, j++) {
        strcpy(suffix, &s1[i]);
        strncpy(prefix, s2, j);
        prefix[j] = '\0';

        if (strcmp(suffix, prefix) == 0)
            lap = j;
    }
    free(suffix);
    free(prefix);
    return lap;
}

int len_str(char **s, int n) {
    if (n == 1)
        return strlen(s[0]);

    int num = n;
    int cur_lap, max_lap;
    int idx_s1, idx_s2;

    while (num > 1) {
        max_lap = 0;
        idx_s1 = 0;
        idx_s2 = 0;

        for (int i = 0; i < n; i++) {
            if (strlen(s[i]) == 0)
                continue;
            for (int j = 0; j < n; j++) {
                if (strlen(s[j]) == 0 || strcmp(s[i], s[j]) == 0)
                    continue;

                cur_lap = overlap(s[i], s[j]);

                if ((cur_lap > max_lap) || (max_lap == 0)) {
                    max_lap = cur_lap;
                    idx_s1 = i;
                    idx_s2 = j;
                }
            }
        }

        char *s_ = (char *) malloc(max_len * sizeof(char));
        char *suff = (char *) malloc(max_len * sizeof(char));

        strcpy(suff, &s[idx_s2][max_lap]);
        strcpy(s_, s[idx_s1]);
        strcat(s_, suff);

        strcpy(s[idx_s1], s_);
        free(s_);

        s[idx_s2][0] = '\0';
        num--;
        free(suff);
    }
    return strlen(s[idx_s1]);
}

int main() {
    int n = 0;
    scanf("%d", &n);

    char **s = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        s[i] = malloc(max_len * sizeof(char));
        scanf("%s", s[i]);
    }

    printf("%d", len_str(s, n));
    for (int i = 0; i < n; i++) free(s[i]);
    free(s);

    return 0;
}