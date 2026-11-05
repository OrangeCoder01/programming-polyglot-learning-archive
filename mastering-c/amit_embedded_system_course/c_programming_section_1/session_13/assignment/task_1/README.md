# Task (1):
- Performing linked list appending operations:
    - (1) Display List.   
    - (2) Search value in list and return index/position.
    - (3) Count Length (number of nodes including Head).
    - (4) Create List.  
    - (5) Insert a new node in the Beginning (appending before Head's node).
    - (6) Insert a new node in the End (appending after Tail's node).
    - (7) Insert a new node in the Position (appending a user defined node's psoitions).
    - (8) Delete node  (deleting user-selected node).
    - (9) Reverse List (Reversing the order of the nodes).


````
    Visualizing the insertion dynamic in linked list:

    Let addresses be represented as letters for simplicity:

                                                new_node = *head_double_pointer (1)
                             +-------------------------------------------------------+
                            \|/                                                      |                                                       
                            \|/                                                      |
                             |        *head_double_pointer = new_node (2)            |
                         Head (A) ----------------+                                  |                                                           
            +---------------+---------------+     |               +---------------+---------------+  
            |     Data      |     Link      |     |               |     Data      |     Link      |     
            |    (Info)     |    (B)        |     +---------+     |    (Info)     |    (X)        |  
            +---------------+---------------+               |     +---------------+---------------+  
                                                            |                             |
                        Node (B)                            |                            /|\
            +---------------+---------------+               |                            /|\
            |     Data      |     Link      |               +-----------------------------+ 
            |    (Info)     |    (C)        |       
            +---------------+---------------+
                        Node (C)                         
            +---------------+---------------+
            |     Data      |     Link      |   
            |    (Info)     |    (D)        |
            +---------------+---------------+
                        Node (D)                         
            +---------------+---------------+
            |     Data      |     Link      |   
            |    (Info)     |    (NULL)     |
            +---------------+---------------+

````