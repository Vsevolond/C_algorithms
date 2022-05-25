#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Elem
{
    struct Elem *next;
    char *word;
};

int compare(struct Elem *head)
{
    return (int)strlen(head->word) - (int)strlen(head->next->word);
}

void swap(struct Elem *head)
{
    char *tmp = head->word;
    head->word = head->next->word;
    head->next->word = tmp;
}

struct Elem *bsort (struct Elem *list)
{
    struct Elem *i, *j;
    for (i = list; i != NULL; i = i->next) {
        for (j = list; j->next != NULL; j = j->next) {
            if (compare(j) > 0) swap(j);
        }
    }
    return list;
}

void get_string(char *s) {
    char c;
    int i = 0;
    scanf("%c", &c);
    while (c != '\n' && c != EOF && c != '\0') {
        s[i] = c;
        scanf("%c", &c);
        i++;
    }
    s[i] = '\0';
}

int wcount(const char *s, int n) {
    int i = 0, k = 0;
    while (s[i] != '\0') {
        if (s[i] != ' ') {
            k++;
            while (s[i] != ' ' && s[i] != '\0') i++;
        } else i++;
    }
    return k;
}


int main() {
    char str[1000];
    get_string(str);
    int len = (int)strlen(str);
    int n = wcount(str, len);

    char *mass[n];
    for (int i = 0; i < n; i++) mass[i] = malloc(1000 * sizeof(char));

    int k = 0, num = 0;
    while (num < len) {
        if (str[num] != ' ') {
            char token[1000] = {'\0'};
            int j = 0;
            while (str[num] != ' ' && str[num] != '\0') {
                token[j] = str[num];
                j++;
                num++;
            }
            token[j] = '\0';
            int len_token = (int)strlen(token);
            memcpy(mass[k], token, len_token + 1);
            k++;
        } else num++;
    }

    struct Elem list[n];
    list[0].word = malloc(1000 * sizeof(char));
    memcpy(list[0].word, mass[0], strlen(mass[0]) + 1);
    for (int i = 1; i < n; i++) {
        list[i].word = malloc(1000 * sizeof(char));
        memcpy(list[i].word, mass[i], strlen(mass[i]) + 1);
        list[i - 1].next = &list[i];
    }
    list[n - 1].next = NULL;

    struct Elem *sorted_list = bsort(list);
    for (int i = 0; i < n; i++) {
        printf("%s ", sorted_list[i].word);
        free(sorted_list[i].word);
        free(mass[i]);
    }
    return 0;
}

