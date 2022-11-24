#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack_t *create_stack(unsigned capacity) {
    struct stack_t *stack = (struct stack_t*)malloc(sizeof(struct stack_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *) malloc (stack->capacity * sizeof(int));
    return stack;
}

int is_full(struct stack_t *stack) {
    return stack->top == stack->capacity - 1;
}

int is_empty(struct stack_t *stack) {
    return stack->top == -1;
}

void push(struct stack_t *stack, int data) {
    if (is_full(stack)) {
        printf ("Can not push to stack, stack is full!\n");
        return;
    }
    stack->top ++;
    stack->arr[stack->top] = data;
    printf("%d pushed to stack\n", data);
}

void pop(struct stack_t *stack) {
    if (is_empty(stack)) {
        printf ("Cannot pop from stack, stack is empty!\n");
        return;
    }
    stack->top --;
}

int peek(struct stack_t *stack) {
    if (is_empty(stack)) {
        printf ("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void print_stack(struct stack_t *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf ("%d ", stack->arr[i]);
    }
}

// int main() {
//     struct stack_t *stack = create_stack(5);

//     for (int i = 0; i < 7; i ++) {
//         push(stack, i);
//     }

//     print_stack(stack);
//     pop(stack);
//     print_stack(stack);

//     return 0;
// }