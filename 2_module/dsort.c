#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dsort (char *s) {
    int *cnt = malloc(26 * sizeof(int));
    memset(cnt, 0, 26 * sizeof(int));
    for (char *sym = s; *sym != '\0'; sym++) {
        cnt[*sym - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        while (cnt[i] > 0) {
            *s = (char)(i + 'a');
            cnt[i]--;
            s++;
        }
    }
    free(cnt);
}

int main() {
    char *str = malloc(10000000 * sizeof(char));
    scanf("%s", str);
    dsort(str);
    printf("%s", str);
    free(str);
    return 0;
}