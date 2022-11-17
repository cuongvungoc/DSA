#include <stdio.h>
#include <stdlib.h>

struct node_t {
	int data;
	struct node_t* next;
};

void printList(struct node_t* n)
{
	while (n != NULL) {
		printf(" %d ", n->data);
		n = n->next;
	}
}

void push (struct node_t **head_ref, int new_data) {
    // 1. Allocate node
    struct node_t *new_node = (struct node_t *) malloc (sizeof(struct node_t));

    // 2. Put in the data
    new_node->data = new_data;

    // 3. Make next of new node as head
    new_node->next = (*head_ref);

    // 4. Move the head to point to new node
    (*head_ref) = new_node;

}

void append(struct node_t** head_ref, int new_data) {
    struct node_t *new_node = (struct node_t *) malloc (sizeof(struct node_t));
    struct node_t *last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    // If linked list is empty, make the new node
    if (head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Else treversal to the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node
    last->next = new_node;// insert (head->next, 9);
    return;
}

void insert (struct node_t *pre_node, int new_data) {
    // Check if pre node is NULL
    if (pre_node == NULL) {
        printf ("The given previous node can not be NULL");
        return;
    }

    struct node_t *new_node = (struct node_t*) malloc (sizeof(struct node_t));
    
    new_node->data = new_data;

    new_node->next = pre_node->next;

    pre_node->next = new_node;
}

void delete_at (struct node_t **head, int position) {
    struct node_t *temp;
    struct node_t *prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *head = (*head)->next;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
                if (prev == NULL){
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void delete_by_key(struct node_t **head, int key) {
    struct node_t *temp = *head;
    struct node_t *prev;

    // If head hold the key value
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    } 

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main()
{
	struct node_t* head = NULL;
	push (&head, 5);
    push (&head, 4);
    push (&head, 3);
    push (&head, 2);
    push (&head, 1);
    append (&head, 6);
    append (&head, 7);
    append (&head, 8);
    insert (head->next->next, 9);
    printList(head);
    printf("\n");
    delete_at (&head, 1);
    delete_by_key (&head, 5);


	// Function call
	printList(head);

	return 0;
}