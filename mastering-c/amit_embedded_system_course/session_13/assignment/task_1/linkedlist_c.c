#include "linkedlist_c.h"



int main(void)
{
    Node_t *Node_ptr = NULL;
    create_node(10.0f, &Node_ptr);

    if (Node_ptr != NULL) 
    {
        printf("Node created successfully!\n");
        printf("Address of Head variable in main:  %p\n", (void *)&Node_ptr);
        printf("Address stored inside Head pointer: %p\n", (void *)Node_ptr);
        printf("Value stored in Head->data:         %.1f\n", Node_ptr->data);
        printf("Value stored in Head->link:         %p\n", (void *)Node_ptr->link);
    }
    
    free(Node_ptr);
    Node_ptr = NULL;
    return 0;
}