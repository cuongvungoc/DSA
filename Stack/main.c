// #include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct stack_t *stack = create_stack(5);

    for (int i = 0; i < 7; i ++) {
        push(stack, i);
    }

    print_stack(stack);
    pop(stack);
    print_stack(stack);

    return 0;
}