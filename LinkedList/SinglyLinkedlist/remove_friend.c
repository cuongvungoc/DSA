#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/linkedlist.h"

int find_position (struct node_t *node) {
    int position = 1;
    bool del_friend = false;
    while (node != NULL && node->next != NULL) {
        if (node->data < node->next->data) {
            del_friend = true;
            break;
        }
        position ++;
        node = node->next;
    }

    if (del_friend == true){
        return position;
    }
    else {
        return -1;
    }
}

int main () {
    
    FILE *fp;
    fp = fopen ("input_rmfriend.txt", "r++");
    int t;
    fscanf (fp, "%d", &t);
    int n, k;
    int popularity;
    for (int i =0; i < t; i++) {
        // printf ("=========================\n");

        struct node_t *head = NULL;
        fscanf (fp, "%d", &n);
        fscanf (fp, "%d", &k);

        for (int j = 0; j < n; j++) {
            fscanf (fp, "%d", &popularity);
            append (&head, popularity);
        }
        // printf ("k = %d, n = %d\n", k, n);
        // printList (head);
       
        // Remove friend
        while (k > 0) {
            int position = find_position (head);
            if (position == -1) {
                delete_at (&head, n);
                n --;
            }
            else {
                delete_at (&head, position);
                n --;
            }
            k --;
        }
    
        printList (head);
        free (head);
    }
    return 0;
}