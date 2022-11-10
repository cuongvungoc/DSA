#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_array (array_list *list, int init_size) {
    list->arr = malloc (init_size * sizeof(int));
    list->used = 0;
    list->size = init_size;
}

void free_array (array_list *list) {
    free(list->arr);
    list->arr = NULL;
    list->size = list->used = 0;
}

void add_element_to_array (array_list *list, int data) {
    if (list->used == list->size) {
        list->size <<= 1;
        list->arr = realloc(list->arr, list->size * sizeof(int));
    }
    list->arr[list->used++] = data;
}

void remove_last_element (array_list *list) {
    if (list->used > 0) {
        list->arr[list->used - 1] = 0;
        list->used--;
    }
}

void insert_element_at (array_list *list, int index, int data) {
    if (list->used == list->size) {
        list->size <<= 1;
        list->arr = realloc(list->arr, list->size * sizeof(int));
    }

    for (int i = list->used - 1; i >= index; i--) {
        list->arr[i + 1] = list->arr[i];
    }

    list->arr[index] = data;
    list->used += 1;
}

void remove_element_at (array_list *list, int index) {
    if (list->used > 0) {
        for (int i = index; i < list->used - 1; i++) {
            list->arr[i] = list->arr[i + 1];
        }
    }
    remove_last_element (list);
}

void remove_element_by_value (array_list *list, int value) {
    for (int i = 0; i < list->used; i++) {
        if (list->arr[i] == value) {
            remove_element_at (list, i);
            break;
        }
    }
}
