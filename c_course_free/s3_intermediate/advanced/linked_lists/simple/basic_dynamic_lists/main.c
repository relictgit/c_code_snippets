#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;           /* value of the list */
    struct node *next; /* point to the next list element */
} node_t;

void print_list(node_t *head);
node_t *create_new_node(int val);

int main() {
    node_t *tmp;
    node_t *head;

    tmp = create_new_node(32);  /* creating first element */
    head = tmp;                 /* start link point */
    tmp = create_new_node(500); /* create second element */
    tmp->next = head;           /* link it as next element by setting head to it */
    head = tmp;                 /* update head with tmp */
    tmp = create_new_node(99);
    tmp->next = head;
    head = tmp;

    print_list(head);

    return 0;
}

void print_list(node_t *head) {
    node_t *temp = head;

    while(temp != NULL) {
        printf("%d - ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

node_t *create_new_node(int val) {
    node_t *result = malloc(sizeof(node_t));
    result->val = val;
    result->next = NULL;
    return result;
}
