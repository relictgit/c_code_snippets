#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;           /* value of the list */
    struct node *next; /* point to the next list element */
} node_t;

void print_list(node_t *head);
node_t *create_new_node(int val);
node_t *insert_at_head(node_t **head, node_t *node_to_insert);

int main() {
    node_t *tmp;
    node_t *head;

    /* without using method insert_at_head() */
    /* for(int i = 0; i < 25; i++) { */
    /*     tmp = create_new_node(i); */
    /*     tmp->next = head; */
    /*     head = tmp; */
    /* } */

    for(int i = 0; i < 25; i++) {
        tmp = create_new_node(i);
        head = insert_at_head(&head, tmp);
    }

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
    /* bad coding example, notice that malloc takes node_t
     * this will cause problems when changing the variable later on. */
    /* node_t *result = malloc(sizeof(node_t)); */
    /* here is how it should be implemented for malloc.
     * notice that you repead the variable which will let you know
     * the issue once you change the variable later on. */
    node_t *result = malloc(sizeof(*result));
    result->val = val;
    result->next = NULL;
    return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}
