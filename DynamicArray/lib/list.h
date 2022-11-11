#ifndef LIST_H
#define LIST_H

typedef struct {
    int *arr;
    int used;
    int size;
} array_list;

void init_array (array_list *list, int init_size);
void free_array (array_list *list);

void add_element_to_array (array_list *list, int data);
void remove_last_element (array_list *list);

void insert_element_at (array_list *list, int index, int data);
void remove_element_at (array_list *list, int index);
void remove_element_by_value (array_list *list, int value);
void display (array_list *list);

#endif