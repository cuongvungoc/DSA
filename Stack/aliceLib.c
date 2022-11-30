#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define size 10

// return 1 if c is alphabet and return 0 if not
int is_alphabet(char c) {
    if (c >= 97 && c <=122) {
        return 1;
    }
    return 0;
}

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void revere_from(char *str, int begin, int end) {
    for (int i = begin; i < begin + ((end - begin) / 2); i++) {
        swap(&str[i], &str[begin + end - i - 1]);
    }
}

int main() {
    FILE *fp;
    fp = fopen ("input.txt", "r+");
    char str[size];

    // Read the input from file
    fscanf(fp, "%s", &str);
    for (int i =0; i < sizeof(str); i ++) {
        printf("%c", str[i]);
    }
    
    struct stack_t *lib = create_stack(size);

    /* If str[i] = '/', push to stack,
     * else reverse from peek
     */
    for (int i = 0; i < size; i++) {
        if (is_alphabet(str[i]) == 0) {
            if (str[i] == '/') {
                push(lib, i);
            }
            else {
                revere_from (&str, peek(lib), i + 1);
                pop(lib);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (is_alphabet(str[i]) == 1) {
            printf("%c", str[i]);
        }
    }

    return 0;
}