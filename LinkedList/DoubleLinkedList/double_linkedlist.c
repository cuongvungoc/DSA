#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int data;
    struct node_t *next;
    struct node_t *prev;
};

void push(struct node_t **head_ref, int new_data) {
    // Alocate the new node
    struct node_t *new_node = (struct node_t *) malloc (sizeof(struct node_t));
    
    // Put in the data
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    // If the DDL is empty, make the new node
    if((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }

    // Change head to the new node
    (*head_ref) = new_node;
}

void append(struct node_t **head_ref, int new_data) {
    // Alocate the node
    struct node_t *new_node = (struct node_t *) malloc (sizeof(struct node_t));
    struct node_t *last = *head_ref;
    
    // Put in the data
    new_node->data = new_data;
    new_node->next = NULL;
    
    // If DLL is empty, make the new the node
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->prev = NULL;
        return;
    }

    // Traversal DDL
    while (last->next != NULL) {
        last = last->next;
    }

    // Append the new node
    new_node->prev = last;
    last->next = new_node;
    return;
}

void insert_after (struct node_t *pre_node, int new_data) {
    if (pre_node == NULL) {
        printf("The given node cannot be NULL");
        return;
    }
    // Allocate the new node
    struct node_t *new_node = (struct node_t *) malloc (sizeof(struct node_t));
    
    // Put in the data
    new_node->data = new_data;

    new_node->next = pre_node->next;
    pre_node->next = new_node;

    new_node->prev = pre_node;
    if(new_node->next != NULL) {
        new_node->next->prev = new_node;
    } 
}

void insert_before (struct node_t *next_node, int new_data) {
    if (next_node == NULL) {
        printf ("The given after node can not be NULL");
        return;
    }

    // Allocate the new node
    struct node_t *new_node = (struct node_t *) malloc (sizeof(struct node_t));

    // Put in the data
    new_node->data = new_data;

    new_node->prev = next_node->prev;
    next_node->prev = new_node;

    new_node->next = next_node;
    if (new_node->prev != NULL) {
        new_node->prev->next = new_node;
    }
}

void delete_node (struct node_t **head_ref, struct node_t *del_node) {
    if (*head_ref == NULL || del_node == NULL) {
        return;
    }

    if (*head_ref == del_node) {
        *head_ref = del_node->next;
    }

    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }

    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }

    free (del_node);
}

void delete_at (struct node_t **head_ref, int position) {
    if (*head_ref == NULL || position <= 0) {
        return;
    }

    struct node_t *current = *head_ref;

    for (int i = 1; current != NULL && i < position; i++) {
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    delete_node (head_ref, current);
}

void reverse (struct node_t *head) {
    struct node_t *left = head;
    struct node_t *right = head;

    while (right->next != NULL) {
        right = right->next;
    }

    while (left != right && left->prev != right) {
        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next;
        right = right->prev;
    }

}

void print_list (struct node_t *node) {
    struct node_t *last = (struct node_t *) malloc (sizeof(struct node_t));
    printf("\n%s\n", "Traversal in forward direction");
    while (node != NULL) {
        printf ("%d ", node->data);
        last = node; 
        node = node->next;
    }

    printf("\n%s\n", "Traversal in backward direction");
    while (last != NULL) {
        printf ("%d ", last->data); 
        last = last->prev;
    }
}

int main() {
    struct node_t *head = NULL;
    append(&head, 5);
    push(&head, 1);
    push(&head, 2);
    append(&head, 4);
    push(&head, 3);
    insert_after(head, 6);
    insert_before(head->next->next, 7);
    delete_node(&head, head->next);
    delete_at(&head, 2);
    print_list(head);
    reverse(head);
    print_list(head);
}