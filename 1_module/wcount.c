#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int wcount(char *s) {
    int i = 0, n = (int)strlen(s), k = 0;
    while (i < n) {
        if (s[i] != ' ' && s[i] != '\t') {
            k++;
            while (s[i] != ' ' && s[i] != '\t' && i < n) i++;
        } else i++;
    }
    return k;
}

int main() {
    char *s = (char*)malloc(10000 * sizeof(char));
    gets(s);
    printf("%d", wcount(s));
    free(s);
    return 0;
}

