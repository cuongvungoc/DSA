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

int gcd_in_range (int *arr, int len, int l, int r) {
    int *temp = (int*) malloc (2 * sizeof(int));
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] >= l && arr[i] <= r) {
            temp[count] = arr[i];
            count ++;
        }
    }
    int gcd_t = gcd (temp[0], temp[1]);
    for (int i = 2; i < count; i++) {
        gcd_t = gcd (gcd_t, temp[i]);
    }
    return gcd_t;
}

int main () {

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
            break;
        case 2:
            fscanf (fp, "%d", &x);
            remove_element_by_value (&list, x);
            break;
        case 3:
            fscanf (fp, "%d", &x);
            printf ("%d\n", smallest (list.arr, list.used, x));
            break;
        case 4:
            fscanf (fp, "%d", &l);
            fscanf (fp, "%d", &r);
            printf ("%d\n", gcd_in_range (list.arr, list.used, l, r));
            break;
        default:
            break;
        }
    }

    return 0;
}