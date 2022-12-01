#include <stdio.h>
#include <stdlib.h>

#define alphabet_size 26

void replace_string(char *str1, char *str2, int len) {
    int check = 1;

    /* Create arr1 and arr2 to count the 
     * number of occurrences of each alphabet charactor
     */ 
    int arr1[alphabet_size];
    int arr2[alphabet_size];
    for (int i = 0; i < alphabet_size; i++) {
        arr1[i] = 0;
        arr2[i] = 0;
    }

    for (int i = 0; i < len; i++) {
        arr1[str1[i] - 'a']++;
        arr2[str2[i] - 'a']++;
    }

    // If number of different char > 2 => NO else => YES
    for (int i = 0; i < len; i++) {
        if (abs(arr1[i] - arr2[i]) > 2) {
            check = 0;
            break;
        }
    }
    
    if (1 == check) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

int main() {
    FILE *fp = fopen("./input/replace_input.txt", "r++");
    int tc;
    fscanf(fp, "%d", &tc);
    
    int len;
    for (int i = 0; i < tc; i++) {
        fscanf(fp, "%d", &len);
        char str1[len];
        char str2[len];
        fscanf(fp, "%s", str1);
        fscanf(fp, "%s", str2);
        replace_string(str1, str2, len);
    }

    return 0;
}