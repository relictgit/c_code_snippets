#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;           /* value of the list */
    struct node *next; /* point to the next list element */
} node_t;

void print_list(node_t *head);

int main() {
    node_t n1;
    node_t n2;
    node_t n3;
    node_t *head;

    n1.val = 45;
    n2.val = 8;
    n3.val = 99;

    /* link them up */
    head = &n1;    /* specify the starting point */
    n1.next = &n2; /* linking nodes */
    n2.next = &n3;
    n3.next = NULL; /* stoping point */

    /* adding a val to the middle */
    node_t n4;
    n4.val = 900;
    n4.next = &n3;

    /* removing the first node */
    n2.next = &n4;
    head = head->next;
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
