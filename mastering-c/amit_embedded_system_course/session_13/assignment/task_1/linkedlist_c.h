#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    float data;
    struct Node *link;
}Node_t;



/*
    (1) Display List   
    (2) Search   
    (3) Count Length   
    (4)) Create List   
    (5) Insert a new node @ Beginning   
    (6) Insert a new node @ End   
    (7) Insert a new node @ Position   
    (8) Delete node   
    (9) Reverse List 
*/


void display_list(Node_t *head_ptr) /* Task (1) */
{
    if(head_ptr == NULL) 
    {
        printf("[]"); 
        return;
    }

    Node_t *temp_ptr = head_ptr;
    printf("[");
    while(temp_ptr != NULL)
    {
        printf(" %.2f", &temp_ptr->data);
        temp_ptr = temp_ptr->link;

        if(temp_ptr != NULL) { printf(", "); }
    }
    printf("]");
}




int search_node(float target, Node_t **head_double_ptr) /* Task (2) */
{
    Node_t *ptr = *head_double_ptr; /* The first asterisk '*' is initialization as pointer and the second one is dereferencing */
    /* ptr here is stack allocated not heap allocated, it is deleted upon function termination. */
    int index = 0;
    while(ptr != NULL)
    {
        if(ptr->data == target) 
        {
            return index; 
        }
        ptr = ptr->link; /* ptr += 1 is invalid due to its applicability for contiguous block array, and linked list is not contiguous. */
        index += 1;
    }

    printf("Warning: Element with value: %.2f is not found, returning '-1'", target);
    return -1;
}



int count_len(Node_t *head_ptr) /* Task (3) */
{
    int length = 1;
    Node_t *temp_ptr = head_ptr;

    while(temp_ptr != NULL)
    {
        temp_ptr->link;
        length += 1;
    }
    return length;
}



void create_node(float value, Node_t **head_double_ptr) /* Task (4) */
{
    Node_t *new_node_ptr =  (Node_t*) malloc(sizeof(Node_t));

    if(new_node_ptr == NULL)
    {
        printf("Error: Heap Memory Allocation failed (probably heap memory insufficiency).");
        return;
    }
    
    new_node_ptr->data = value;
    new_node_ptr->link = NULL;

    *head_double_ptr = new_node_ptr;
}




void insert_node_beginning(Node_t **head_double_ptr, float value) /* Task (5) */
{
    Node_t *new_node = (Node_t *) malloc(sizeof(Node_t));

    if(new_node == NULL)
    {
        printf("Error: Heap Memory Allocation failed (probably heap memory insufficiency).");
        return;
    }

    new_node->data = value;

    new_node->link = *head_double_ptr;
    *head_double_ptr = new_node;
}



void insert_node_ending(Node_t **head_ptr, float value) /* Task (6) */
{
    Node_t *new_node = (Node_t *) malloc(sizeof(Node_t));
    
    if(new_node == NULL)
    {
        printf("Error: Heap Memory Allocation failed (probably heap memory insufficiency).");
        return;
    }

    new_node->data = value;
    new_node->link = NULL;

    if(*head_ptr == NULL) 
    {
        *head_ptr = new_node; 
        return;
    }

    Node_t *temp_ptr = *head_ptr;
    while(temp_ptr != NULL)
    {
        if(temp_ptr->link == NULL)
        {
            temp_ptr->link = new_node;
            return;
        }
        temp_ptr = temp_ptr->link;
    }
}




void insert_node_position(Node_t **head_ptr, int position, float value) /* Task (7) */
{
    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    if (new_node == NULL) 
    {
        printf("Error: Heap Memory Allocation failed (probably heap memory insufficiency).");
        return;
    }
    
    new_node->data = value;

    if (position == 0 || *head_ptr == NULL) 
    {
        new_node->link = *head_ptr;
        *head_ptr = new_node;
        return;
    }

    Node_t *temp_ptr = *head_ptr;
    for (int i = 0; i < position - 1 && temp_ptr->link != NULL; i++) 
    {
        temp_ptr = temp_ptr->link;
    }

    new_node->link = temp_ptr->link;
    temp_ptr->link = new_node;
}



void delete_node(Node_t **head_ptr, float target) /* Task (8) */
{
    if (*head_ptr == NULL) 
    {
        return;
    }

    Node_t *temp_ptr = *head_ptr;
    Node_t *prev_ptr = NULL;

    if (temp_ptr != NULL && temp_ptr->data == target) 
    {
        *head_ptr = temp_ptr->link;
        free(temp_ptr);
        return;
    }

    while (temp_ptr != NULL && temp_ptr->data != target) 
    {
        prev_ptr = temp_ptr;
        temp_ptr = temp_ptr->link;
    }

    if (temp_ptr == NULL) 
    {
        return;
    }

    prev_ptr->link = temp_ptr->link;
    free(temp_ptr);
}




void reverse_list(Node_t **head_ptr) /* Task (9) */
{
    Node_t *prev_ptr = NULL;
    Node_t *current_ptr = *head_ptr;
    Node_t *next_ptr = NULL;

    while (current_ptr != NULL) 
    {
        next_ptr = current_ptr->link;
        current_ptr->link = prev_ptr;
        prev_ptr = current_ptr;
        current_ptr = next_ptr;
    }

    *head_ptr = prev_ptr;
}
