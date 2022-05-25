#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CircleBuffer
{
    int *data;
    int capacity;
    int count;
    int head;
    int tail;
};

void queue_init(struct CircleBuffer *cb, int n)
{
    cb->data = malloc(n * sizeof(int));
    cb->capacity = n;
    cb->count = 0;
    cb->head = 0;
    cb->tail = 0;
}

int queue_empty(struct CircleBuffer cb)
{
    return cb.count == 0;
}

void enqueue(struct CircleBuffer *cb, int x)
{
    cb->data[cb->tail] = x;
    cb->tail++;
    if(cb->tail == cb->capacity) {
        cb->capacity *= 2;
        cb->data = realloc(cb->data, cb->capacity * sizeof(int));
    }
    cb->count++;
}

int dequeue(struct CircleBuffer *cb)
{
    int x = cb->data[cb->head];
    cb->head++;
    if (cb->head == cb->capacity) cb->head = 0;
    cb->count--;
    return x;
}

int find(char **mass, char *s, int n) {
        for (int i = 0; i < n; i++) {
            if (strcmp(mass[i], s) == 0) return i;
        }
    }

    int main() {
        char *actions[] = {"ENQ", "DEQ", "EMPTY"};
        int n;
        scanf("%d", &n);
        struct CircleBuffer buf;
        queue_init(&buf, 4);
        for (int i = 0; i < n; i++) {
            char *op = malloc(10 * sizeof(char));
            scanf("%s", op);
            int ind = find(actions, op, 3);
            int x;
            switch (ind) {
                case 0:
                    scanf("%d", &x);
                    enqueue(&buf, x);
                    break;
                case 1:
                    printf("%d\n", dequeue(&buf));
                    break;
                case 2:
                    if (queue_empty(buf)) printf("%s\n", "true");
                    else printf("%s\n", "false");
                    break;
            }
            free(op);
        }
        free(buf.data);
    return 0;
}