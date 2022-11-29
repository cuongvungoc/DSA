#ifndef SORTING_H
#define SORTING_H

void swap(int *a, int *b);
void print_array(int *arr, int size);

void bubble_sort(int *arr, int size);

void selection_sort(int *arr, int size);

void insertion_sort(int *arr, int size);

void merge(int *arr, int p, int q, int r);
void merge_sort(int *arr, int l, int r);

void heapify(int *arr,int n, int i);
void heap_sort(int *arr, int n);

#endif