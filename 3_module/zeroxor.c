#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
typedef struct Tree Tree;

struct Node
{
    long key, val;
    Node *parent, *left, *right;
};

struct Tree
{
    Node *root;
};

Node *tree_find_node(Tree *tree, long key)
{
    Node *node  = tree->root;
    while(node && node->key != key) {
        if(key < node->key) node = node->left;
        else node = node->right;
    }
    return node;
}

Node *tree_insert_node(Tree *tree, long key, long val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->val = val;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    if(!tree->root) {
        tree->root = new_node;
        return tree->root;
    }

    Node *node = tree->root;
    while(1) {
        if(key < node->key)
        {
            if(!node->left)
            {
                node->left = new_node;
                new_node->parent = node;
                break;
            }
            node = node->left;
        }
        else
        {
            if(!node->right)
            {
                node->right = new_node;
                new_node->parent = node;
                break;
            }
            node = node->right;
        }
    }

    return new_node;
}

void tree_clear_node(Node *node)
{
    if(node->left) tree_clear_node(node->left);
    if(node->right) tree_clear_node(node->right);
    free(node);
}

void tree_clear(Tree tree)
{
    if(tree.root)
        tree_clear_node(tree.root);
}

int main()
{
    int n;
    scanf("%d", &n);
    Tree tree;
    tree.root = NULL;
    long cnt = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
        long x;
        scanf("%ld", &x);
        sum ^= x;
        Node *node = tree_find_node(&tree, sum);
        if(!node) node = tree_insert_node(&tree, sum, 0);
        node->val++;
        if(sum == 0) cnt += node->val;
        else cnt += node->val - 1;
    }
    printf("%ld", cnt);
    tree_clear(tree);
    return 0;
}