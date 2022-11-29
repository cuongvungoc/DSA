#include <stdio.h>
#include <stdlib.h>

struct queue_t {
    int front;
    int rear;
    int size;
    int capacity;
    int *array;
};

struct queue_t *create_queue(unsigned capacity) {
    struct queue_t *queue = (struct queue_t*)malloc(sizeof(struct queue_t));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int is_full(struct queue_t *queue) {
    return (queue->size == queue->capacity);
}

int is_empty(struct queue_t *queue) {
    return (queue->size == 0);
}

void enqueue(struct queue_t *queue, int data) {
    if (is_full(queue)) {
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;
    queue->size ++; 
    printf("%d enqueue to queue!\n", data);
}

int dequeue(struct queue_t *queue) {
    if (is_empty(queue)) {
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(struct queue_t *queue) {
    if (is_empty(queue)) {
        return -1;
    }
    return queue->array[queue->front];
}

int rear(struct queue_t *queue) {
    if (is_empty(queue)) {
        return -1;
    }
    return queue->array[queue->rear];
}

void display(struct queue_t *queue) {
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    struct queue_t *queue = create_queue(10);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    dequeue(queue);
    display(queue);
    printf("front: %d\n", front(queue));
    printf("rear: %d\n", rear(queue));
    return 0;
}