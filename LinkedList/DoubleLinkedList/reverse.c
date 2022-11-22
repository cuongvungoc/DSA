#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

void reverse_subll (struct node_t *left, struct node_t *right) {
    while (left != right && left->prev != right) {
        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next;
        right = right->prev;
    }
}

void solve_problem (struct node_t *node) {
    struct node_t *left = node;
    struct node_t *right = node;
    while (node != NULL) {
        if (node->data % 2 == 0) {
            left = node;
            while (node->data % 2 == 0 && node->next != NULL) {
                node = node->next;
            }
            right = node->prev;
            if (left != right) {
                reverse_subll (left, right);
            }
            node = node->next;
        }
        else {
            node = node->next;
        }
    }
}

int main() {
    struct node_t* head = NULL;
    FILE *fp;
    fp = fopen ("input.txt", "r+");
    int n;
    int temp;
    fscanf(fp, "%d", &n);

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &temp);
        append(&head, temp);
    }
    print_list(head);
    // reverse_subll (head->next, head->next->next->next->next);
    solve_problem (head);
    print_list(head);

    return 0;
}