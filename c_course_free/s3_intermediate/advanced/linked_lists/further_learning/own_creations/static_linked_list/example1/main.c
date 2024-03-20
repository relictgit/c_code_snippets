#include <stdio.h>
#include <stdlib.h>

/* simple creation example of a static linked list */

typedef struct node {
    int val;
    struct node *next;
} node_t;

void print_list(node_t *head);

int main() {
    node_t *head = malloc(sizeof(*head));
    node_t *n1 = malloc(sizeof(*n1));
    node_t *n2 = malloc(sizeof(*n2));

    head = n1;
    n1->val = 1;
    n1->next = n2;
    n2->val = 2;
    n2->next = NULL;

    print_list(head);

    return 0;
}

void print_list(node_t *head) {
    node_t *current = head;
    while(current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}
