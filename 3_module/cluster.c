#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


struct Time
{
    int start, dur;
};

struct Pair
{
    int value, key;
};

struct PriorityQueue {
    struct Pair *heap;
    int capacity;
    int count;
};

void swap(struct Pair *a, struct Pair *b)
{
    struct Pair t = *a;
    *a = *b;
    *b = t;
}

int priority_queue_sift_down(struct Pair *list, int n)
{
    int capacity = 0, i = 0;
    while (i < n / 2)
    {
        int l = i * 2 + 1, r = l + 1, j = l;

        if(r < n && list[r].key > list[l].key)
            j = r;

        if(list[i].key >= list[j].key)
            return capacity;

        swap(&list[i], &list[j]);
        i = j;
        capacity = i;
    }
    return capacity;
}

void priority_queue_init(struct PriorityQueue *q, int capacity)
{
    q->capacity = capacity;
    q->count = 0;
    q->heap = malloc(capacity * sizeof(struct Pair));
    for (int i = 0; i < capacity; i++) {
        q->heap[i].value = 0;
        q->heap[i].key = 0;
    }
}

int priority_queue_pop(struct PriorityQueue *q)
{
    struct Pair x = q->heap[0];
    q->heap[0].key = INT_MIN;
    q->count = priority_queue_sift_down(q->heap, q->capacity);
    return x.value;
}

void priority_queue_push(struct PriorityQueue *q, struct Pair elem)
{
    int i = q->count;
    q->count = i + 1;
    q->heap[i] = elem;
    while (i > 0 && q->heap[(i - 1) / 2].key < q->heap[i].key)
    {
        swap(&q->heap[i], &q->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct PriorityQueue q;
    priority_queue_init(&q, n);
    int k;
    scanf("%d", &k);
    struct Time t[k];
    for(int i = 0; i < k; i++)
    {
        int start, dur;
        scanf("%d %d", &start, &dur);
        t[i].start = start;
        t[i].dur = dur;
    }
    int total_time = 0;
    for(int i = 0; i < k; i++)
    {
        struct Time time = t[i];
        int start_time = priority_queue_pop(&q);
        if (time.start > start_time)
            start_time = time.start;

        start_time += time.dur;
        if (total_time < start_time) total_time = start_time;

        struct Pair new_time;
        new_time.value = start_time;
        new_time.key = -start_time;
        priority_queue_push(&q, new_time);
    }

    printf("%d", total_time);
    free(q.heap);
    return 0;
}
