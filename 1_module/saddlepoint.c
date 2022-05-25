#include <stdio.h>
#include <stdint.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n][m];
    int str[n], st[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    }
    for (int i = 0; i < n; i++) str[i] = a[i][0];
    for (int j = 0; j < m; j++) st[j] = a[0][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (str[i] < a[i][j]) str[i] = a[i][j];
            if (st[j] > a[i][j]) st[j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (a[i][j] == str[i] && a[i][j] == st[j]) {
                printf("%d %d", i, j);
                return 0;
            }
    }
    printf("%s", "none");
    return 0;
}
