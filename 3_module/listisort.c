#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Elem Elem;

struct Elem {
        struct Elem *prev, *next;
        int v;
};

struct DoubleLinkedList {
    struct Elem *limit, *sort;
};

void double_linked_list_init(struct DoubleLinkedList *list) {
    struct Elem *lim;
    lim = malloc(sizeof(struct Elem));
    list->limit = lim;
    list->limit->next = list->limit;
    list->limit->prev = list->limit;
    list->sort = list->limit;
}

void double_linked_list_push(struct DoubleLinkedList *list, int x) {
    struct Elem *a;
    a = malloc(sizeof(struct Elem));
    a->v = x;
    a->next = list->limit;
    a->prev = list->limit->prev;
    list->limit->prev->next = a;
    list->limit->prev = a;
}

int double_linked_list_moveafter(struct Elem *a, struct Elem *prev){
    if(a == prev || a == prev->next) return 1;
    else {
        a->next->prev = a->prev;
        a->prev->next = a->next;
        a->next = prev->next;
        a->next->prev = a;
        a->prev = prev;
        prev->next = a;
    }
    return 0;
}

void sort(struct DoubleLinkedList *list, int n) {
    list->sort = list->limit->next;
    while (list->sort != list->limit->prev){
        int move = 0;
        struct Elem *a = list->sort->next;
        struct Elem *loc = list->sort;
        while( loc != list->limit && loc->v > a->v) {
            loc = loc->prev;
            move++;
        }
        double_linked_list_moveafter(a, loc);
        if(!move) list->sort = list->sort->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct DoubleLinkedList list;
    double_linked_list_init(&list);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        double_linked_list_push(&list, x);
    }
    sort(&list, n);
    for (struct Elem *a = list.limit->next; a != list.limit; a = a->next) {
        printf("%d ", a->v);
        free(a->prev);
    }
    free(list.sort);
    return 0;
}