#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
    int word_cnt;
    struct Node **next;
    int terminal;
};

void init_node(struct Node *node) {
    node->next = malloc(26 * sizeof(struct Node*));
    for (int i = 0; i < 26; i++) {
        node->next[i] = NULL;
    }
    node->word_cnt = 0;
    node->terminal = 0;
}

struct Trie
{
    struct Node *root;
};

void init_trie(struct Trie *trie, struct Node *node) {
    trie->root = node;
}

void trie_insert(struct Trie *trie, char *str)
{
    struct Node *node = trie->root;
    int n = (int)strlen(str);
    for(int i = 0; i < n; i++)
    {
        char c = str[i];
        if (node->next[c - 'a'] == NULL) {
            struct Node *child_node = malloc(sizeof(struct Node));
            init_node(child_node);
            node->next[c - 'a'] = child_node;
        }
        node = node->next[c - 'a'];
        node->word_cnt++;
    }
    node->terminal = 1;
}

void trie_delete(struct Trie *trie, char *str)
{
    struct Node *node = trie->root;
    struct Node *child_node;
    int n = (int)strlen(str);
    for(int i = 0; i < n; i++)
    {
        char c = str[i];
        child_node = node->next[c - 'a'];
        child_node->word_cnt--;
        if (child_node->word_cnt == 0)
        {
            node->next[c - 'a'] = NULL;
            break;
        }
    }
    child_node->terminal = 0;
}

int trie_pref_count(struct Trie *trie, char *pref)
{
    struct Node *node = trie->root;
    int cnt = 0, n = (int)strlen(pref);
    for(int i = 0; i < n; i++)
    {
        char c = pref[i];
        node = node->next[c - 'a'];
    }
    if (node->terminal) cnt = node->word_cnt;
    return cnt;
}

int find(char **mass, char *s, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(mass[i], s) == 0) return i;
    }
}

int main() {
    char *actions[] = {"INSERT", "DELETE", "PREFIX"};
    struct Trie trie;
    struct Node node;
    init_node(&node);
    init_trie(&trie, &node);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char op[10];
        scanf("%s", op);
        int ind = find(actions, op, 3);
        char str[100000];
        scanf("%s", str);
        switch (ind) {
            case 0:
                trie_insert(&trie, str);
                break;
            case 1:
                trie_delete(&trie, str);
                break;
            case 2:
                printf("%d\n", trie_pref_count(&trie, str));
                break;
        }
    }
}