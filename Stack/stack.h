#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct stack_t {
    int top;
    unsigned capacity;
    int *arr;
};

struct stack_t *create_stack(unsigned capacity);

int is_full(struct stack_t *stack);
int is_empty(struct stack_t *stack);

void push(struct stack_t *stack, int data);
void pop(struct stack_t *stack);

int peek(struct stack_t *stack);

void print_stack(struct stack_t *stack);

#endif