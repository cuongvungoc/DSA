#include <stdio.h>
#include <stdlib.h>
#include "lib/sorting.h"

void counting_sort (int *arr, int size) {
    // Find the max element of array
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    int *count = (int*)malloc((max + 1) * sizeof(int));
    int *output = (int*)malloc((max + 1) * sizeof(int));

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Comulative the sum and store in count array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}


int main() {
    int arr[] = {6, 4, 8, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    // bubble_sort(arr, size);
    // selection_sort(arr, size);
    // insertion_sort(arr,size);
    // merge_sort(arr,0, size - 1);
    // heap_sort(arr, size);
    counting_sort(arr, size);
    print_array(arr, size);
    return 0;
}