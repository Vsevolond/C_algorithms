#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long max(long long a, long long b) {
    return a > b ? a : b;
}

struct Pair {
    long long val, max;
};

struct DoubleStack
{
    int capacity;
    int top_1;
    int top_2;
    struct Pair *data;
};

int double_stack_empty_1(struct DoubleStack *ds)
{
    return ds->top_1 == 0;
}

int double_stack_empty_2(struct DoubleStack *ds)
{
    return ds->top_2 == ds->capacity - 1;
}

void double_stack_init(struct DoubleStack *ds, int n)
{
    ds->capacity = n;
    ds->top_1 = 0;
    ds->top_2 = n - 1;
    ds->data = malloc(n * sizeof(struct Pair));
}

void double_stack_push_1(struct DoubleStack *ds, long long x)
{
    if (double_stack_empty_1(ds)) ds->data[ds->top_1].max = x;
    else ds->data[ds->top_1].max = max(ds->data[ds->top_1 - 1].max, x);
    ds->data[ds->top_1].val = x;
    ds->top_1++;
}

void double_stack_push_2(struct DoubleStack *ds, long long x)
{
    if (double_stack_empty_2(ds)) ds->data[ds->top_2].max = x;
    else ds->data[ds->top_2].max = max(ds->data[ds->top_2 + 1].max, x);
    ds->data[ds->top_2].val = x;
    ds->top_2--;
}

int double_stack_pop_1(struct DoubleStack *ds)
{
    ds->top_1--;
    return ds->data[ds->top_1].val;
}

int double_stack_pop_2(struct DoubleStack *ds)
{
    ds->top_2++;
    return ds->data[ds->top_2].val;
}

void double_stack_clear(struct DoubleStack *ds)
{
    free(ds->data);
    ds->data = NULL;
    ds->capacity = 0;
    ds->top_1 = -1;
    ds->top_2 = -1;
}

void enqueue(struct DoubleStack *ds, long long x)
{
    double_stack_push_1(ds, x);
}


long long dequeue(struct DoubleStack *ds)
{
    if(double_stack_empty_2(ds))
    {
        while(!double_stack_empty_1(ds))
        {
            long long a = double_stack_pop_1(ds);
            double_stack_push_2(ds, a);
        }
    }
    return double_stack_pop_2(ds);
}

int find(char **mass, char *s, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(mass[i], s) == 0) return i;
    }
}

long long double_stack_max (struct DoubleStack *ds) {
    if (double_stack_empty_1(ds)) return ds->data[ds->top_2 + 1].max;
    else if (double_stack_empty_2(ds)) return ds->data[ds->top_1 - 1].max;
    else return max(ds->data[ds->top_1 - 1].max, ds->data[ds->top_2 + 1].max);
}

int main() {
    char *actions[] = {"ENQ", "DEQ", "EMPTY", "MAX"};
    int n;
    scanf("%d", &n);
    struct DoubleStack st;
    double_stack_init(&st, n * 2);
    for (int i = 0; i < n; i++) {
        char op[10] = {'\0'};
        scanf("%s", op);
        int ind = find(actions, op, 4);
        long long x;
        switch (ind) {
            case 0:
                scanf("%lld", &x);
                enqueue(&st, x);
                break;
            case 1:
                printf("%lld\n", dequeue(&st));
                break;
            case 2:
                if (double_stack_empty_1(&st) && double_stack_empty_2(&st)) printf("%s\n", "true");
                else printf("%s\n", "false");
                break;
            case 3:
                printf("%lld\n", double_stack_max(&st));
        }
    }
    double_stack_clear(&st);
    return 0;
}
