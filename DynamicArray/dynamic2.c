#include "lib/list.h"
#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort (int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                swap (&arr[i], &arr[j]);
            }
        }
    }
}

int smallest (int *arr, int len, int x) {
    int *temp = (int*) malloc (len * sizeof(int));
    // assign temp array to array list
    for (int i = 0; i < len; i++) {
        temp[i] = arr[i];
    }
    sort (temp, len);
    return temp[x - 1];
}

int gcd (int a, int b) {
    while (a - b != 0) {
        if (a > b) {
            a -=b;
        }
        else {
            b -= a;
        }
    }
    return a;
}

int main () {
    // int a[] = {1, 5, 3, 9, 8};
    // // sort (a, 5);
    // int m = smallest (a, 5, 5);
    // printf ("%d\n", m);

    // printf ("%d\n", gcd(15,30));

    
    FILE *fp;
    fp = fopen ("input.txt", "r+");
    array_list list;
    init_array (&list, 5);
    int q;
    int x, k, l, r;
    fscanf (fp, "%d", &q);  //read number of queries

    for (int i = 0; i < q; i++) {
        fscanf (fp, "%d", &k);
        switch (k)
        {
        case 1:
            fscanf (fp, "%d", &x);
            add_element_to_array (&list, x);
            printf ("%s\n", "Case 1 called !");
            break;
        case 2:
            fscanf (fp, "%d", &x);
            remove_element_by_value (&list, x);
            printf ("%s\n", "Case 2 called !");
            break;
        case 3:
            fscanf (fp, "%d", &x);
            printf ("%d\n", smallest (list.arr, list.used, x));
            printf ("%s\n", "Case 3 called !");
        case 4:
            fscanf (fp, "%d", &l);
            fscanf (fp, "%d", &r);
            printf ("%s\n", "Case 4 called !");

        default:
            break;
        }
    }

    return 0;
}