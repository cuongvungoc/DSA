#include <stdio.h>
#include "lib/list.h"

// Compare two sub string, return 1 if equal, return 0 if not equal
int compare_str (char *str1, char* str2, int sub_len) {
    for (int i = 0; i < sub_len; i ++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    // printf ("%s\n", "Compare call");
    return 1;
} 

int find_sublen (char *arr, int len) {
    int sub_len = len / 3;
    while (sub_len > 0) {
        // compare sub string in first and last string
        if (1 == compare_str (arr, (arr + len - sub_len), sub_len)) {
            // check substring in the middle
            for (int i = sub_len + 1; i < len - sub_len - 1; i++) {
                if (1 == compare_str (arr, (arr + i), sub_len)) {
                    return sub_len;
                }
            }
        }
        sub_len--;
    }
    return sub_len;
} 

void password (char *arr, int len) {
    int pass_len = find_sublen (arr, len);
    if (pass_len == 0) {
        printf ("%s\n", "Just a legend");
    }
    else {
        for (int i = 0; i < pass_len; i ++) {
            printf ("%c", arr[i]);
        }
        printf("\n");
    }
}

int main () {
    char *arr1 = "fix123fix123fix";
    char *arr2 = "abcdabc";
    password (arr1, 15);
    password (arr2, 7);
    return 0;
}