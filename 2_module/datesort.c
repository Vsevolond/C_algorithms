#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max (int a, int b) { return a > b ? a : b; }

struct Date {
    int Year, Month, Day;
};

int key (struct Date d, int n) {
    if (n == 0) return d.Day;
    if (n == 1) return d.Month;
    if (n == 2) return d.Year;
}

void distributionSort (int num, int m, struct Date *d, int n) {
    int *cnt = malloc((m + 1) * sizeof(int));
    memset(cnt, 0, (m + 1) * sizeof(int));
    for (int j = 0; j < n; j++) {
        int k = key(d[j], num);
        cnt[k]++;
    }
    for (int i = 1; i <= m; i++) {
        cnt[i] = cnt[i] + cnt[i - 1];
    }
    struct Date *sorted = malloc(n * sizeof(struct Date));
    for (int j = n - 1; j >= 0; j--) {
        int k = key(d[j], num);
        int i = cnt[k] - 1;
        cnt[k] = i;
        sorted[i] = d[j];
    }
    memcpy(d, sorted, n * sizeof(struct Date));
    free(sorted);
    free(cnt);
}

void radixSort(int *m, struct Date *d, int n) {
    for (int i = 0; i < 3; i++) {
        distributionSort(i, m[i], d, n);
    }
}


int main() {
    int n;
    scanf("%d", &n);
    struct Date *dates = malloc(n * sizeof(struct Date));
    int m_Year = 0, m_Month = 0, m_Day = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
        m_Year = max(m_Year, dates[i].Year);
        m_Month = max(m_Month, dates[i].Month);
        m_Day = max(m_Day, dates[i].Day);
    }
    int m[3] = {m_Day, m_Month, m_Year};
    radixSort(m, dates, n);
    for(int i = 0; i < n; i++) printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    free(dates);
    return 0;
}