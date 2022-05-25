#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int *arr, int lo, int hi) {
    int r = arr[hi];
    int i = lo-1;
    for(int j = lo; j < hi; j++){
        if(arr[j]<r){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, hi);
    return i+1;
}

void selectionSort(int *num, int l, int r)
{
    int min, temp;
    for (int i = l; i < r; i++)
    {
        min = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (num[j] < num[min])
                min = j;
        }
        temp = num[i];
        num[i] = num[min];
        num[min] = temp;
    }
}

void quickSort(int *arr, int lo, int hi, int m) {
    if (lo < hi) {
        int q = partition(arr, lo, hi);
        if ((hi - q) < m) selectionSort(arr, q + 1, hi);
        else quickSort(arr, q + 1, hi, m);
        if ((q - lo) < m) selectionSort(arr, lo, q - 1);
        else quickSort(arr, lo, q - 1, m);
    }
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quickSort(a, 0, n - 1, m);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    free(a);
    return 0;
}

