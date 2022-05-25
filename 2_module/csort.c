#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wcount(const char *s, int n, int *k) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] != ' ') {
            (*k)++;
            while (s[i] != ' ' && s[i] != '\0') i++;
        } else i++;
    }
}

void csort(char *src, char *dest) {
    int n = 0;
    int len = (int)strlen(src);
    wcount(src, len, &n);
    char *mass[n];
    for (int i = 0; i < n; i++) mass[i] = malloc(1000 * sizeof(char));

    int k = 0, i = 0;
    while (i < len) {
        if (src[i] != ' ') {
            char token[1000] = {'\0'};
            int j = 0;
            while (src[i] != ' ' && src[i] != '\0') {
                token[j] = src[i];
                j++;
                i++;
            }
            token[j] = '\0';
            int len_token = (int)strlen(token);
            memcpy(mass[k], token, len_token + 1);
            k++;
        } else i++;
    }

    int cnt[n];
    memset(cnt, 0, n * sizeof(int));
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int len_i = (int)strlen(mass[i]);
            int len_j = (int)strlen(mass[j]);
            if (len_i > len_j) cnt[i]++;
            else cnt[j]++;
        }
    }

    char *res[n];
    for (i = 0; i < n; i++) res[i] = malloc(1000 * sizeof(char));
    for (i = 0; i < n; i++) {
        int len_i = (int)strlen(mass[i]);
        memcpy(res[cnt[i]], mass[i], len_i + 1);
    }
    int len_dest = 0;
    for (i = 0; i < n; i++) {
        int len_res = (int)strlen(res[i]);
        memcpy(dest + len_dest, res[i], len_res + 1);
        len_dest += len_res;
        if (i == n - 1) dest[len_dest] = '\0';
        else {
            dest[len_dest] = ' ';
            len_dest++;
        }
    }
    for (i = 0; i < n; i++) {
        free(mass[i]);
        free(res[i]);
    }
}

void get_string(char *s) {
    char c;
    int i = 0;
    scanf("%c", &c);
    while (c != '\n' && c != EOF && c != '\0') {
        s[i] = c;
        scanf("%c", &c);
        i++;
    }
    s[i] = '\0';
}

int main() {
    char str[1000] = {'\0'};
    get_string(str);
    char buf[1000] = {'\0'};
    csort(str, buf);
    printf("%s", buf);
    return 0;
}