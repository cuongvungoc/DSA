#include <stdio.h>

#define alphabet_size 26

// Find min element of an array
int min_arr(int *arr, int len) {
    int min = 10000;
    for (int i = 1; i < len; i++) {
        if (arr[i] < min && arr[i] != 0) {
            min = arr[i];
        }
    }
    return min;
}

int string_query(char *str, int left, int right) {
    int arr[alphabet_size];
    for (int i = 0; i < alphabet_size; i++) {
        arr[i] = 0;
    }

    for (int i = left; i <= right; i++) {
        arr[str[i] - 'a']++;
    }

    int min = min_arr(arr, alphabet_size);
    int num = 0;
    
    // Count the number of char should be deleted
    for (int i = 0; i < alphabet_size; i++) {
        if (arr[i] > min) {
            num += (arr[i] - min);
        }
    }
    return num;
}


int main() {
    FILE *fp = fopen("./input/queries_input.txt", "r++");
    int N, Q;
    int L, R;
    char str[N];

    fscanf(fp, "%d", &N);
    fscanf(fp, "%d", &Q);
    fscanf(fp, "%s", str);
    
    for (int i = 0; i < Q; i++) {
        fscanf(fp, "%d", &L);
        fscanf(fp, "%d", &R);

        int del = string_query(str, L, R);
        printf("%d\n", del);
    }

    return 0;
}