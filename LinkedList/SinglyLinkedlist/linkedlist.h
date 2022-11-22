#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct node_t {
	int data;
	struct node_t* next;
};

void printList(struct node_t* n);

void push (struct node_t **head_ref, int new_data);
void append(struct node_t** head_ref, int new_data);
void insert (struct node_t *pre_node, int new_data);

void delete_at (struct node_t **head, int position);
void delete_by_key(struct node_t **head, int key);

#endif