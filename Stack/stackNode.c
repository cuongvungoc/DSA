#include <stdio.h>
#include <stdlib.h>

struct stack_node_t
{
    int data;
    struct stack_node_t *next;
};

struct stack_node_t *new_node(int data)
{
    struct stack_node_t *stack_node = (struct stack_node_t *)malloc(sizeof(struct stack_node_t));
    stack_node->data = data;
    stack_node->next = NULL;
    return stack_node;
}

int is_empty(struct stack_node_t *root)
{
    return !root;
}

void push(struct stack_node_t **root, int data)
{
    struct stack_node_t *stack = new_node(data);
    *root = stack;
    printf("%d pushed to the stack !\n", data);
}

void pop(struct stack_node_t **root)
{
    if (is_empty(*root))
    {
        printf("Can not pop from stack, stack is empty!");
        return;
    }
    struct stack_node_t *temp = *root;
    *root = (*root)->next;
    int poped = temp->data;
    free(temp);
    printf("%d poped from the stack !\n", poped);
    // return poped;
}

int peek(struct stack_node_t *root)
{
    if (is_empty(root))
    {
        printf("Stack is empty!");
        return -1;
    }

    return root->data;
}

int main()
{
    struct stack_node_t *root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    pop(&root);
    return 0;
}