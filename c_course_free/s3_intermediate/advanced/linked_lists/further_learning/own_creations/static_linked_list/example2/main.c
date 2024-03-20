#include <stdio.h>
#include <stdlib.h>

/* data structure for double linked lists */
/*typedef struct d_node
{
    int val;
    struct d_node *next;
    struct d_node *previous;
} d_node_t;*/

/* data structure for linked lists */
typedef struct node {
    int val;
    struct node *next;
} node_t;

void print_list(node_t *head);

int main() {
    // struct node *head = (struct node *) malloc(sizeof(struct node));
    node_t *head = malloc(sizeof(*head));
    head->val = 1;
    head->next = NULL;

    node_t *second = malloc(sizeof(*second));
    head->next = second;
    second->val = 2;
    second->next = NULL;

    node_t *third = malloc(sizeof(*third));
    second->next = third;
    third->val = 3;
    third->next = NULL;

    print_list(head);
    return 0;
}

void print_list(node_t *head) {
    node_t *current = head;
    while(current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}
