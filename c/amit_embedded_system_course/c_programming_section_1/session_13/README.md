# Session (13): Dynamic Memory Allocation & Linked Lists

Learned (mixed with personal research):

Note:
````
    This session introduces Dynamic Memory Allocation (DMA) using the <stdlib.h> library in C,
    exploring Heap memory management, runtime memory functions (malloc, calloc, realloc, free),
    and foundational dynamic data structures like Single Linked Lists.
````
${\color{red}\text{VERY IMPORTANT NOTE: (1)}}$
````
    There is one clear distiction between Stack allocation and heap allocation.
    Stack allocation demands that all variables/instances have names
````
```c
        int x;
        float z;
        char a;
```
````
    But that is not the case with heap allocation as the variable can physically exist but does not
    have a name, only address; thus is managed by a pointer.

    Very important example:
````
```c
        int *ptr = (int*)malloc(sizeof(int))
```
````
    The previous code commands that a piece of memory space to be controlled by pointer "ptr".
    The variable's name is not created, but its physical address exists.

    Unlike the static allocation example:
````
```c
        int var;
        int *ptr = &var;
```
````
    This is a very crucial distinction; the linked list contains many perplexing and confounding
    methodologies involving pointer logic and memory allocation to achieve its ends.
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
            | 0x100 | Data does not matter
            +-------+
                |
                v
            +-------+-------+     +-------+-------+     +-------+-------+
            |   10  | 0x400 | --> |   20  | 0x050 | --> |   30  | NULL  |
            +-------+-------+     +-------+-------+     +-------+-------+
            Address: 0x100        Address: 0x400        Address: 0x050
```
<br>

${\color{red}\text{VERY IMPORTANT NOTE: (2)}}$
````
    Head is a pointer to struct "Node_t" user-defined datatype, but it is different from normal nodes;
    it is intended to be a swapping placeholder for appending nodes by swapping addresses.
````
${\color{red}\text{VERY IMPORTANT NOTE: (3)}}$
````
        Please disregard the way addresses numerically are presented in here, as the values of addresses are represented in 
        hexadecimal numbering system not in decimal form;
        but I am focusing in explaining the concepts rather than correcting my perplexing mixture of hexadecimal and decimal numbering systems.


    There are many points need to be addressed:

        The instance from struct "Node" has 3 directly relatable content:
            (1) The address of the instance itself:
            
                Node_t node_1; -------> This line initialized an instance "node_1" from struct "Node_t".
                which means that this instance has a distinct address of its own.

                Node_1 -----> Address: 0x0A1
            

            (2) Each data of the instance adopt their own distinct addresses.

                &Node_1.data ----> The float value data has address (arbitrary) 0x0A11
                &Node_1.link ----> Pointer linker data has address (arbitrary) 0x0A12
            

            (3) The data of the instance contain a value.

                Node_1.data   ----> A numerical floating point value.
                Node_1.link   ----> The address of the next instance "node_2"

                Inisde heap memory:


                    Remember the first variable inside a holder (instance/array) has the address of it:
                        Data (float value variable) is the first variable, thus it holds the address of its instance (alias address).

                    Node_1: 0x0A41                                                          
                +---------------+-----------------+                                                     
                | Data (0x0A41) | Link (0X012452) |                                                                                                                                       
                | 10.0          | 0x0A42          |  -------->>----------------------->>>>> Node_2: 0x0A42     
                +---------------+-----------------+                         +---------------+-----------------+
                                                                            | Data  (0x0A42)| Link (0X034254) |
                            random address                                  | -23.4         | 0x0A43          |
                                                                            +---------------+-----------------+                                      
                                                        random Address                             |
                    Node_3: 0x0A43   <<<<<---------------------------------<<----------------------+       
                +---------------+-----------------+
                | Data  (0x0A43)| Link (0X004233) | ------------------>>-------------+
                | 2231.445      | 0x0A44          |         random address           |                  random address
                +---------------+-----------------+                                  |              
                                                                                     |
                    random address                                                   |
                                                                                     |
                    Node_4: 0x0A44   <<<<<-------------------<<----------------------+
                +---------------+-----------------+
                | Data (0x0A44) | Link (0X033331) |             random address
                | 22.005        | Null            |
                +---------------+-----------------+
            
                
            The addresses of float value "data" and the instance (Node) struct pointer "link" are not considered due to not being used, 
            but the acknowledgment of their own addresses and not confusing them with other addresses is crucial 
            for comprehending the linked list and many other future C concepts.     
````
<br>

${\color{red}\text{VERY IMPORTANT NOTE: (4)}}$
````
    What is the difference between:
````
```c
        Node_t node_x; /* Instance*/

        Node_t *node_x; /* Pointer to an instance */

        Node_t **node_x; /* Pointer to a Pointer to an instance */
```
````
    "node_x" is the actual instance that contains both the float data and the link.
    
    "node_y" is a struct pointer of "Node" that point to any instances of "Node", it could point towards the memory address of "node_x".

    "node_z" is a double struct pointer (higher order pointer) of "Node" that points towards the address of a pointer of struct "Node"
    that points to an instance of struct "Node".

    A simple analogy for clarification:

        A wireless controller controls an RC car, one can move a car by a click of a bottom (change a value of a variable 
        by passing the new value by reference) while there is a second controller that control the first controller wirelessly.
    
    Why need a "double pointer"?

        Because a pointer can change its pointing address by being reassigned, double pointer can apply same method with pointers.
````
```c
            int x, y, z;
            int *p = &x;
            p = &y;
            p = &z;
            /* Same pointer, different values. */
```
````
    The pointer can be used for managing different variables (within the same datatype), a "double pointer" can manage
    different pointers.

    It is the same as hierarchy of power or rank, the higher order can control the lower order ones, their instance, and other companion pointers,
    while the lower order ones can control instances only; haveing no control over its companions or the higher order pointers:
        
        the higher order wireless controller can control the nature of the lower order wireless controller; it can control in what
        RC car it should control (What address does it point to) or control a specific RC car (dereferencing).

    When one wants to controls a pointer by using pass by reference in a function, the input should be an address, but a pointer holds an
    address, so the solution is to introduce an address of an address.
````
```c
    void push_front(Node **head, int value)
    {
        Node *n = malloc(sizeof *n);

        if (n == NULL){ return; }

        n->info = value;
        n->link = *head;

        *head = n;          /* changes the caller's head pointer */
    }
```
````
    For visualization:

            Before:   head ──► [20 | ──►] ──► [30 | NULL]
                                0x100          0x200

            push_front(&head, 10):

            1. Node *n = malloc(sizeof *n);   → a brand-new block at, say, 0x400
            2. n->info = value;               → sets info = 10 in the NEW node (n), not in head
            3. n->link = *head;               → new node points to the old head (0x100)
            4. *head = n;                     → the caller's head pointer now holds 0x400

            After:    head ──► [10 | ──►] ──► [20 | ──►] ──► [30 | NULL]
                                0x400          0x100          0x200

````


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

<br>

|P.O.C|**${\color{blue}\text{Stack Allocation}}$**| **${\color{green}\text{Heap Allocation}}$**|
|:---|:---|:---|
|**Declaration**|`Node_t node1;`|`Node_t *new_node = (Node_t *) malloc(sizeof(Node_t));`|
|**Instance Name**|Has a variable name (node1)|Anonymous / Unnamed|
|**How to Access**|Directly by name using dot operator: `node1.data`|Indirectly via pointer using arrow operator: `new_node->data`|
|**Lifetime**|Automatically destroyed when function ends|Persists in memory until explicitly erased with `free(new_node)`|
|**Location**|Contiguous Stack frame|Anywhere available on the Heap|
