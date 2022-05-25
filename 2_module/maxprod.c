#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ld long double

void maximize(int *res, int n, const ld *a) {
    ld max_sum = a[0], sum = 0;
    int l = 0, r = 0, min_pos = -1;

    for (int i = 0; i < n; i++) {
        sum += a[i];

        if (sum > max_sum) {
            max_sum = sum;
            l = min_pos + 1;
            r = i;
        }
        if (sum < 0) {
            sum = 0;
            min_pos = i;
        }
    }

    res[0] = l, res[1] = r;

}

int main(void) {

    int n;
    int *res = (int *) malloc(2 * sizeof(int));

    scanf("%d", &n);

    ld *a = (ld *) malloc(n * sizeof(ld));

    for (int i = 0; i < n; i++) {
        int c, d;
        char f;
        scanf("%d%c%d", &c, &f, &d);
        a[i] = log(c) - log(d);
    }

    maximize(res, n, a);

    printf("%d %d", res[0], res[1]);

    free(res);
    free(a);

    return 0;
}