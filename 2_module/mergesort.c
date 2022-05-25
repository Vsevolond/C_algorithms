#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *a, int p, int q, int r);
void part(int *a,int p,int r);
void InsertionSort(int l, int r, int *mass);


int main(void) {
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    part(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    free(a);
    return 0;
}

void part(int *a, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        if ((q - p + 1) < 5) InsertionSort(p, q, a);
        else part(a, p,q);
        if ((r - q) < 5) InsertionSort(q + 1, r, a);
        else part(a,q+1, r);
        merge(a, p, q, r);
    }
}

void merge(int *a, int p, int q, int r)
{
    int n1 = q - p + 1, n2 = r - q;
    int L[n1 + 1], R[n2 + 1], i, j, k;
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    for (i = 0; i < n1; i++)
        L[i] = a[p + i];

    for (j = 0; j < n2; j++)
        R[j] = a[q + j + 1];

    i=0;
    j=0;

    for (k = p; k <= r; k++)
    {
        if(abs(L[i]) <= abs(R[j]))
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}

void InsertionSort(int l, int r, int *mass)
{
    int newElement, location;

    for (int i = l + 1; i <= r; i++)
    {
        newElement = mass[i];
        location = i - 1;
        while(location >= l && abs(mass[location]) > abs(newElement))
        {
            mass[location+1] = mass[location];
            location = location - 1;
        }
        mass[location+1] = newElement;
    }
}