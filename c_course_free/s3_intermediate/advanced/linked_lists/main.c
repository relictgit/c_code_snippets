#include <stdio.h>
#include <stdlib.h>

/* TODO:    You must implement the function remove_by_value
 *          which receives a double pointer to the head and
 *          removes the first item in the list which has
 *          the value val. */

/* REMINDER:    if structs are initialized with typedef
 *              the name after the "}" will be usabel
 *              without allways writing struct <struct_name>.
 *              Notice that in this example for a linked list
 *              you need to provide a alias name beforehand
 *              <struct_alias_name> {.
 *              Here it is necessary because you will need to
 *              pass through the structure itself for the next element
 *              within the list.*/

typedef struct node {
    int val;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    node_t *current = head;

    while(current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t **head) {
    int retval = -1;
    node_t *next_node = NULL;

    if(*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t **head, int val) {
    /* TODO: fill in your code here */
    /* find the first element inside the list
     * and remove the found node with the consisting val */
    /* also as a reminder: please have a delete_list()
     * up and running in order to free memory space.
     * Otherwise you will cause memory leaks. */
    return 0;
}

int main() {
    /* this usage of malloc below is prone tu issues.
     * 1. dirty cast of "(node_t *) malloc [...]"
     * 2. malloc(sizeof(node_t)) --> usage of datatype rather the variable name
     * for 1.: always know your variables and initialize them accordingly
     * so that you are not in the need to do dirty casting
     * for 2.: always use the created variables rather data types.
     * In ase you change your variable you will be save from issues in the long term. */

    /* node_t *test_list = ( node_t * ) malloc(sizeof(node_t)); */
    /* test_list->val = 1; */
    /* test_list->next = ( node_t * ) malloc(sizeof(node_t)); */
    /* test_list->next->val = 2; */
    /* test_list->next->next = ( node_t * ) malloc(sizeof(node_t)); */
    /* test_list->next->next->val = 3; */
    /* test_list->next->next->next = ( node_t * ) malloc(sizeof(node_t)); */
    /* test_list->next->next->next->val = 4; */
    /* test_list->next->next->next->next = NULL; */

    /* here a correct / recommended way of how using malloc below */

    node_t *test_list = malloc(sizeof(*test_list));
    test_list->val = 1;
    test_list->next = malloc(sizeof(*test_list));
    test_list->next->val = 2;
    test_list->next->next = malloc(sizeof(*test_list));
    test_list->next->next->val = 3;
    test_list->next->next->next = malloc(sizeof(*test_list));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
}
