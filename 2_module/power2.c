#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, res = 0;
    scanf("%d", &n);

    int *a = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int v = 1; v < (1 << n); v++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if ((v & (1 << i))) {
                sum += a[i];
            }
        if ((sum & (sum - 1)) == 0) res++;
    }

    printf("%d", res);

    free(a);

    return 0;
}