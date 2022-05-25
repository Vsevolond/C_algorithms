#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Int32
{
    int x;
    unsigned char bytes[4];
};

void distributionSort (int num, union Int32 *d, int n) {
    int *cnt = malloc(256 * sizeof(int));
    memset(cnt, 0, 256 * sizeof(int));
    for (int j = 0; j < n; j++) {
        int k = d[j].bytes[num];
        if (num == 3) k ^= 128;
        cnt[k]++;
    }
    for (int i = 1; i < 256; i++) {
        cnt[i] = cnt[i] + cnt[i - 1];
    }
    union Int32 *sorted = malloc(n * sizeof(union Int32));
    for (int j = n - 1; j >= 0; j--) {
        int k = d[j].bytes[num];
        if (num == 3) k ^= 128;
        int i = cnt[k] - 1;
        cnt[k] = i;
        sorted[i] = d[j];
    }
    memcpy(d, sorted, n * sizeof(union Int32));
    free(sorted);
    free(cnt);
}

void radixSort(union Int32 *d, int n) {
    for (int i = 0; i < 4; i++) {
        distributionSort(i, d, n);
    }
}


int main(void) {
    int n;
    scanf("%d", &n);
    union Int32 *m = malloc(n * sizeof(union Int32));
    for (int i = 0; i < n; i++) scanf("%d", &m[i].x);
    radixSort(m, n);
    for (int i = 0; i < n; i++) printf("%d ", m[i].x);
    free(m);
    return 0;
}