#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

int priority_queue_sift_down(struct Pair *list, int n) {
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
}

struct Pair priority_queue_pop(struct PriorityQueue *q)
{
    struct Pair x = q->heap[0];
    q->heap[0].key = INT_MIN;
    q->count = priority_queue_sift_down(q->heap, q->capacity);
    return x;
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
    int k;
    scanf("%d", &k);
    int size = 0;
    for (int i = 0; i < k; i++) {
        int c;
        scanf("%d", &c);
        size += c;
    }
    struct PriorityQueue queue;
    priority_queue_init(&queue, size);
    for(int i = 0; i < size; i++)
    {
        int val;
        scanf("%d", &val);
        struct Pair x;
        x.value = val;
        x.key = -val;
        priority_queue_push(&queue, x);
    }
    for(int i = 0; i < size; i++)
        printf("%d ", priority_queue_pop(&queue).value);
    free(queue.heap);
    return 0;
}

