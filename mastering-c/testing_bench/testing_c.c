#include <stdio.h>

typedef struct Node /* It is the name of the struct containing two data: (1) The value data, and (2) A pointer with a value holding the address of the next instance of the same struct */
{
    float data;
    struct Node* link;
}Node_t; /* Alias Name, very helpful for code cleaning */

/*
    Note:

        please disregard the way addresses numerically are presented in here, as the values of addresses are represented in hexadecimal numbering system not in decimal form;
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


                    Node_1: 0x0A41                                                          
                +---------------+-----------------+                                                     
                | Data (0x134)  | Link (0X012452) |                                                                                                                                       
                | 10.0          | 0x0A42          |  -------->>----------------------->>>>> Node_2: 0x0A42     
                +---------------+-----------------+                         +---------------+-----------------+
                                                                            | Data  (0x123) | Link (0X034254) |
                            random address                                  | 10.0          | 0x0A43          |
                                                                            +---------------+-----------------+                                      
                                                        random Address                             |
                    Node_3: 0x0A43   <<<<<---------------------------------<<----------------------+       
                +---------------+-----------------+
                | Data  (0x111) | Link (0X004233) | ------------------>>-------------+
                | 10.0          | 0x0A44          |         random address           |                  random address
                +---------------+-----------------+                                  |              
                                                                                     |
                    random address                                                   |
                                                                                     |
                    Node_4: 0x0A44   <<<<<-------------------<<----------------------+
                +---------------+-----------------+
                | Data (0x439)  | Link (0X033331) |             random address
                | 10.0          | Null            |
                +---------------+-----------------+
            
                
            The addresses of float value "data" and the instance (Node) struct pointer "link" are not considered due to not being used, but the acknowledgment of their
            own addresses and not confusing them with other addresses is crucial for comprehending the linked list and many other future C concepts.     
*/



int main(void)
{
    return 0;
}