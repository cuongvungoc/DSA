#include "list.h"
#include <stdio.h>

int main () {
    array_list list;
    init_array (&list, 5);
    for (int i = 0; i < 10; i++) {
        add_element_to_array (&list, i);
    }

    // remove_last_element (&list);
    // insert_element_at (&list, 2, 7);
    // remove_element_by_value (&list, 5);

    for (int i = 0; i < 5; i++) {
        printf ("%d\n", list.arr[i]);
    }

    // for (int i = 0; i < list.used; i++) {
    //     printf ("%d\n", list.arr[i]);
    // }

    free_array (&list);
    return 0;
}