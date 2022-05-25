#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    long a[n];
    for (int i = 0; i < n; i++) scanf("%ld", &a[i]);
    scanf("%d", &k);
    long sum = 0;
    for (int i = 0; i < k; i++) sum += a[i];
    int l = 0, r = k;
    long max = sum;
    while (r < n) {
        sum += (a[r] - a[l]);
        if (sum > max) max = sum;
        r++;
        l++;
    }
    printf("%ld", max);
    return 0;
}