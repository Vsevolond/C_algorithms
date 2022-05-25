#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Stack
{
    int capacity;
    int top;
    int *data;
};

void stack_init(struct Stack *s, int n)
{
    s->data = malloc(n * sizeof(int));
    s->capacity = n;
    s->top = 0;
}

void stack_push(struct Stack *s, int x)
{
    s->data[s->top] = x;
    s->top++;
}

int stack_pop(struct Stack *s)
{
    s->top--;
    return s->data[s->top];
}

int stack_empty(struct Stack s)
{
    return s.top == 0;
}

int find(char **mass, char *s, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(mass[i], s) == 0) return i;
    }
}

int main() {
    char *actions[] = {"CONST", "ADD", "SUB", "MUL", "DIV",
                       "MAX", "MIN", "NEG", "DUP", "SWAP"};
    int n;
    scanf("%d", &n);
    struct Stack st;
    stack_init(&st, n);
    for (int i = 0; i < n; i++) {
        char *op = malloc(10 * sizeof(char));
        scanf("%s", op);
        int ind = find(actions, op, 10);
        int x, a, b;
        switch (ind) {
            case 0:
                scanf("%d", &x);
                stack_push(&st, x);
                break;
            case 1:
                a = stack_pop(&st);
                b = stack_pop(&st);
                stack_push(&st, a + b);
                break;
            case 2:
                a = stack_pop(&st);
                b = stack_pop(&st);
                stack_push(&st, a - b);
                break;
            case 3:
                a = stack_pop(&st);
                b = stack_pop(&st);
                stack_push(&st, a * b);
                break;
            case 4:
                a = stack_pop(&st);
                b = stack_pop(&st);
                stack_push(&st, a / b);
                break;
            case 5:
                a = stack_pop(&st);
                b = stack_pop(&st);
                if(a > b) stack_push(&st, a);
                else stack_push(&st, b);
                break;
            case 6:
                a = stack_pop(&st), b = stack_pop(&st);
                if(a < b) stack_push(&st, a);
                else stack_push(&st, b);
                break;
            case 7:
                a = stack_pop(&st);
                stack_push(&st, -a);
                break;
            case 8:
                a = stack_pop(&st);
                stack_push(&st, a);
                stack_push(&st, a);
                break;
            case 9:
                a = stack_pop(&st), b = stack_pop(&st);
                stack_push(&st, a);
                stack_push(&st, b);
                break;
        }
        free(op);
    }
    printf("%d", stack_pop(&st));
    free(st.data);
    return 0;
}