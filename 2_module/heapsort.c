#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(void *a, void *b, size_t size) {
    char tmp;
    size_t i;
    for (i = 0; i < size; i++) {
        tmp = *((char*) b + i);
        *((char*) b + i) = *((char*) a + i);
        *((char*) a + i) = tmp;
    }
}

int compare_a(const void *first, const void *second) {
    char *a = *((char**)first);
    char *b = *((char**)second);
    int cnt_a = 0, cnt_b = 0;
    int n_a = (int)strlen(a), n_b = (int)strlen(b);

    if (n_a >= n_b) {
        for (int i = 0; i < n_b; i++) {
            if (a[i] == 'a') cnt_a++;
            if (b[i] == 'a') cnt_b++;
        }
        for (int i = n_b; i < n_a; i++) {
            if (a[i] == 'a') cnt_a++;
        }
    } else {
        for (int i = 0; i < n_a; i++) {
            if (a[i] == 'a') cnt_a++;
            if (b[i] == 'a') cnt_b++;
        }
        for (int i = n_a; i < n_b; i++) {
            if (b[i] == 'a') cnt_b++;
        }
    }

    return cnt_a - cnt_b;

}

void sift (void *base, int l, int r, size_t width, int (*compare)(const void *a, const void *b)) {
    int maxChild;
    int done = 0;
    while ((l * 2 <= r) && !done) {
        if (l * 2 == r) maxChild = l * 2;
        else if (compare((char*)base + l * 2 * width, (char*)base + (l * 2 + 1) * width) > 0)
            maxChild = l * 2;
        else maxChild = l * 2 + 1;
        if (compare((char*)base + l * width, (char*)base + maxChild * width) < 0) {
            swap((char*)base + l * width, (char*)base + maxChild * width, width);
            l = maxChild;
        }
        else done = 1;
    }
}

void hsort(void *base, int nel, size_t width, int (*compare)(const void *a, const void *b)) {
    for (int i = nel / 2; i >= 0; i--) {
        sift(base, i, nel - 1, width, compare);
    }
    for (int i = nel - 1; i > 0; i--) {
        swap(base, (char*)base + i * width, width);
        sift(base, 0, i - 1, width, compare);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    char **a = (char **) calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++) {
        a[i] = (char *) calloc(1000, sizeof(char));
        scanf("%s", a[i]);
    }

    hsort(a, n, sizeof(char*), compare_a);

    for (int i = 0; i < n; i++) printf("%s\n", a[i]);

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}