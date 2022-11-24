#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    FILE *fp;
    fp = fopen ("input.txt", "r+");
    char str[10];
    fscanf(fp, "%s", &str);
    for (int i =0; i < 10; i ++) {
        printf("%c", str[i]);
    }

    return 0;
}