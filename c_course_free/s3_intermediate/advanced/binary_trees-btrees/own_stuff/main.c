#include <stdio.h>
#include <stdlib.h>
/*
data structure for binary trees
notice that this data structure
is similar to double linked lists
*/
/*
typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} node_t;

int main()
{
    printf("Hello world!\n");
    return 0;
}
*/

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node_t;

node_t *createnode(int key) {
    node_t *newnode = malloc(sizeof(*newnode));
    newnode->key = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node_t *insertnode(node_t *root, int key) {
    if(root == NULL) {
        return createnode(key);
    }
    if(key < root->key) {
        root->left = insertnode(root->left, key);
    } else if(key > root->key) {
        root->right = insertnode(root->right, key);
    }
    return root;
}

void inorderTraversal(struct node *root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    printf("binary search tree");
    node_t *root = NULL;
    root = insertnode(root, 50);
    insertnode(root, 30);
    insertnode(root, 20);
    insertnode(root, 40);
    insertnode(root, 70);
    insertnode(root, 60);
    insertnode(root, 80);
    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    return 0;
}
