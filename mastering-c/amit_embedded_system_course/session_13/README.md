# Session (13): Dynamic Memory Allocation & Linked Lists

Learned (mixed with personal research):

Note:
````
    This session introduces Dynamic Memory Allocation (DMA) using the <stdlib.h> library in C,
    exploring Heap memory management, runtime memory functions (malloc, calloc, realloc, free),
    and foundational dynamic data structures like Single Linked Lists.
````

&emsp; ${\color{red}\text{(1)}}$: **Dynamic Memory Allocation (DMA)**
<br>

&emsp;&emsp; ${\color{blue}\text{(1.1)}}$: **malloc (Memory Allocation)**  
````
            The malloc function allocates a specified number of uninitialized bytes in Heap memory.
            It returns a void pointer (void*) pointing to the starting address of the allocated block.
            If allocation fails due to insufficient heap space, it returns NULL.

            Syntax:
                void* malloc(size_t size);
````
```c
                #include <stdio.h>
                #include <stdlib.h>

                int main(void) 
                {
                    /* Allocate memory for 10 integers */
                    int *ptr = (int*) malloc(10 * sizeof(int));

                    if (ptr == NULL) 
                    {
                        printf("Memory allocation failed!\n");
                        return 1;
                    }

                    /* Accessing memory using array indexing or pointer arithmetic */
                    ptr[0] = 10;
                    *(ptr + 1) = 20;

                    printf("ptr[0] = %d, ptr[1] = %d\n", ptr[0], *(ptr + 1));

                    free(ptr);
                    return 0;
                }
```
<br>

&emsp;&emsp; ${\color{blue}\text{(1.2)}}$: **calloc (Contiguous Allocation)**  
````
            The calloc function allocates memory for an array of elements, initializes all bytes to ZERO,
            and returns a void pointer to the allocated memory block.

            Syntax:
                void* calloc(size_t num_elements, size_t element_size);
````
```c
                #include <stdio.h>
                #include <stdlib.h>

                int main(void) 
                {
                    int num_elements = 5;
                    int *ptr = (int*) calloc(num_elements, sizeof(int));

                    if (ptr != NULL) 
                    {
                        /* All values are automatically initialized to 0 */
                        for (int i = 0; i < num_elements; i++) 
                        {
                            printf("ptr[%d] = %d\n", i, ptr[i]); /* Prints 0 for all elements */
                        }
                        free(ptr);
                    }
                    return 0;
                }
```
<br>

&emsp;&emsp; ${\color{blue}\text{(1.3)}}$: **realloc (Reallocation)**  
````
            The realloc function resizes a previously allocated memory block without losing existing data.
            If the new size requires moving the block to a new contiguous memory location, realloc handles 
            copying the old data to the new address and freeing the old block automatically.

            Syntax:
                void* realloc(void *ptr, size_t new_size);
````
```c
                #include <stdio.h>
                #include <stdlib.h>

                int main(void) 
                {
                    char *ptr = (char*) malloc(10 * sizeof(char));
                    
                    if (ptr != NULL) 
                    {
                        /* Reallocate memory size from 10 bytes to 20 bytes */
                        char *new_ptr = (char*) realloc(ptr, 20 * sizeof(char));
                        if (new_ptr != NULL) 
                        {
                            ptr = new_ptr;
                            printf("Memory successfully expanded to 20 bytes.\n");
                        }
                        free(ptr);
                    }
                    return 0;
                }
```
<br>

&emsp;&emsp; ${\color{blue}\text{(1.4)}}$: **free & Dangling Pointers**  
````
            Dynamically allocated memory resides on the Heap and persists until explicitly deallocated.
            Failing to free allocated memory leads to Memory Leaks.

            Dangling Pointer:
            Accessing a pointer after calling free() leads to undefined behavior because the memory 
            block has been returned to the system OS / Heap manager.

            Best Practice: Always set the pointer to NULL immediately after freeing it.
````
```c
                int *ptr = (int*) malloc(5 * sizeof(int));
                
                free(ptr);       /* Deallocates memory block */
                /* ptr[0] = 10;  WARNING: Accessing dangling pointer! */
                
                ptr = NULL;      /* Safe Practice: Nullify pointer */
```
<br>

&emsp;&emsp; ${\color{blue}\text{(1.5)}}$: **Memory Allocation Safety & NULL Check** <br>
````
            Heap allocations are not guaranteed to succeed. Always check if the pointer returned by 
            malloc/calloc/realloc is non-NULL before dereferencing it.
````
```c
                int *ptr = (int*) malloc(sizeof(int));

                if (ptr != NULL) 
                {
                    /* Safe to use memory */
                    *ptr = 50;
                    free(ptr);
                } 
                else 
                {
                    /* Memory allocation failed */
                    printf("Error: Heap Out of Memory!\n");
                }
```
<br>

&emsp;&emsp; **Comparing Dynamic Memory Functions:**

| Function | Parameter(s) | Memory Initialization | Typical Use Case |
| :--- | :--- | :--- | :--- |
| **`malloc`** | Total Size (in bytes) | Uninitialized (Contains Garbage Values) | Single allocation when initial values do not matter |
| **`calloc`** | Number of items, Item Size | Cleared to Zero (`0`) | Array allocation requiring guaranteed zero-initialization |
| **`realloc`**| Existing Pointer, New Size | Preserves existing data, uninitialized expansion | Growing/shrinking buffer sizes dynamically |
| **`free`**   | Allocated Pointer | N/A (Deallocates block) | Preventing memory leaks after buffer lifecycle ends |

<br>

&emsp; ${\color{red}\text{(2)}}$: **Introduction to Linked Lists**
<br>

&emsp;&emsp; ${\color{blue}\text{(2.1)}}$: **Node Structure** <br>
````
            A Linked List is a linear dynamic data structure composed of self-referential structures called Nodes.
            Unlike arrays, nodes are not stored in contiguous memory locations.

            Each node consists of two parts:
            1. Info/Data: The actual payload (value/data).
            2. Link/Next: Pointer storing the memory address of the next node.

            +---------------+---------------+
            |     Data      |     Link      |
            |    (Info)     |    (*Next)    |
            +---------------+---------------+
````
```c
                typedef struct Node 
                {
                    int info;           /* Data payload */
                    struct Node *link;  /* Pointer to next node */
                } Node;
```

```
            Linked List Memory Representation:

              HEAD
            +-------+
            | 0x100 |
            +-------+
                |
                v
            +-------+-------+     +-------+-------+     +-------+-------+
            |   10  | 0x400 | --> |   20  | 0x050 | --> |   30  | NULL  |
            +-------+-------+     +-------+-------+     +-------+-------+
            Address: 0x100        Address: 0x400        Address: 0x050
```
<br>

&emsp;&emsp; ${\color{blue}\text{(2.2)}}$: **Arrays vs Linked Lists** <br>

| Feature | Array | Linked List |
| :--- | :--- | :--- |
| **Memory Allocation** | Contiguous static/heap allocation | Non-contiguous dynamic heap allocation |
| **Size** | Fixed at declaration | Dynamic (Grows and shrinks at runtime) |
| **Access Time** | $O(1)$ Direct random access by index | $O(n)$ Sequential traversal required |
| **Insertion / Deletion** | Expensive ($O(n)$ shifting required) | Cheap ($O(1)$ updating pointer references) |

<br>

&emsp;&emsp; ${\color{blue}\text{(2.3)}}$: **Linked List Operations** <br>

&emsp;&emsp;&emsp;&emsp; ${\color{green}\text{(2.3.1)}}$: **Traversing a Linked List** <br>
````
            To traverse a linked list, start with a pointer 'P' set to 'Head'.
            Iterate through nodes by assigning 'P = P->link' until 'P' becomes NULL.
````
```c
                void traverse_list(Node *head) 
                {
                    Node *p = head;

                    while (p != NULL) 
                    {
                        printf("Node Data: %d\n", p->info);
                        p = p->link; /* Advance to the next node */
                    }
                }
```

<br>

&emsp;&emsp;&emsp;&emsp; ${\color{green}\text{(2.3.2)}}$: **Searching in a Linked List** <br>
````
            Searching involves traversing the list node-by-node and comparing 
            the payload ('info') with a target value 'X'.
````
```c
                int search_list(Node *head, int target) 
                {
                    Node *p = head;
                    int pos = 1;

                    while (p != NULL) 
                    {
                        if (p->info == target) 
                        {
                            printf("Found %d at position %d\n", target, pos);
                            return pos;
                        }
                        pos++;
                        p = p->link;
                    }

                    printf("Value %d not found in list.\n", target);
                    return -1;
                }
```
<br>

&emsp; ${\color{red}\text{(3)}}$ **Why Learn**: <br>

&emsp;&emsp; ${\color{blue}\text{(3.1)}}$ **Dynamic Memory Allocation**: <br>
````
            - Efficient RAM Utilization in MCUs:
                Allows reserving memory only when needed during application runtime,
                preventing static over-allocation of precious SRAM.

            - Adaptive Data Buffering:
                Enables processing dynamic network packets, sensor streams, or 
                user input buffers whose lengths are unknown at compile time.
````

&emsp;&emsp; ${\color{blue}\text{(3.2)}}$ **Linked Lists**: <br>
````
            - Dynamic Buffer Management:
                Allows effortless node additions and removals without memory reallocation 
                or costly data copying.

            - Core Building Block:
                Serves as the foundation for queues, stacks, memory managers, and 
                OS task schedulers in embedded environments.
````