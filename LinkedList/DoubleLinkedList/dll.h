#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int data;
    struct node_t *next;
    struct node_t *prev;
};

void push(struct node_t **head_ref, int new_data);
void append(struct node_t **head_ref, int new_data);

void insert_after (struct node_t *pre_node, int new_data);
void insert_before (struct node_t *next_node, int new_data);

void delete_node (struct node_t **head_ref, struct node_t *del_node);
void delete_at (struct node_t **head_ref, int position);

void reverse (struct node_t *head);
void print_list (struct node_t *node);

#endif