#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main () {
    
    FILE *fp;
    fp = fopen ("input_rmfriend.txt", "r++");
    int t;
    fscanf (fp, "%d", &t);
    int n, k;
    int popularity;
    for (int i =0; i < t; i++) {
        struct node_t *head = NULL;
        fscanf (fp, "%d", &n);
        fscanf (fp, "%d", &k);
        for (int j = 0; j < n; j++) {
            fscanf (fp, "%d", &popularity);
            append (&head, popularity);
        }
        printList(head);
    }
    return 0;
}