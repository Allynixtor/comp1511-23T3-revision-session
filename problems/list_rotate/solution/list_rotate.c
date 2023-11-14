#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *rotate(struct node *head, int length, int steps);
struct node *array_to_list(int len, int array[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION
#define MAX_INIT_LIST_LEN 100
int main()
{
    // Need to read in a number of ints into an array
    printf("How many numbers in list?: ");
    int list_size = 0;
    scanf("%d", &list_size);
    int initial_elems[MAX_INIT_LIST_LEN] = {0};
    int n_read = 0;
    while (n_read < list_size && scanf("%d", &initial_elems[n_read]))
    {
        n_read++;
    }

    // create linked list from first set of inputs
    struct node *head = NULL;
    if (n_read > 0)
    {
        // list has elements
        head = array_to_list(n_read, initial_elems);
    }

    // read in number of steps to rotate
    printf("How many steps to rotate?: ");
    int steps;
    scanf(" %d", &steps);

    struct node *new_head = rotate(head, list_size, steps);
    print_list(new_head);

    return 0;
}

// Rotates a list by a certain number of steps
// Returns the head of the rotated list.
struct node *rotate(struct node *head, int length, int steps)
{
    int new_tail_position = length - steps % length - 1;

    struct node *new_tail = head;
    for (int counter = 0; counter < new_tail_position; counter++)
    {
        new_tail = new_tail->next; // find the new tail
    }

    struct node *old_tail = new_tail;
    while (old_tail->next != NULL)
    {
        old_tail = old_tail->next; // find the old end of the list
    }

    old_tail->next = head;                  // the old end is linked to the old head
    struct node *new_head = new_tail->next; // the new head is the node currently after the new tail
    new_tail->next = NULL;                  // the new tail is the new end of the list

    return new_head;
}

// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *array_to_list(int len, int array[])
{
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0)
    {
        struct node *n = malloc(sizeof(struct node));
        assert(n != NULL);
        n->next = head;
        n->data = array[i];
        head = n;
        i -= 1;
    }
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head)
{
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next)
    {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL)
        {
            printf(", ");
        }
    }
    printf("]\n");
}