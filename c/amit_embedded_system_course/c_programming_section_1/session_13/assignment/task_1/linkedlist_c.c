#include "linkedlist_c.h"
void display_list(Node_t *head_ptr);
int search_node(float target, Node_t **head_double_ptr);
int count_len(Node_t *head_ptr);
void create_node(float value, Node_t **head_double_ptr);
void insert_node_beginning(Node_t **head_double_ptr, float value);
void insert_node_ending(Node_t **head_ptr, float value);
void insert_node_position(Node_t **head_ptr, int position, float value);
void delete_node(Node_t **head_ptr, float target);
void reverse_list(Node_t **head_ptr);