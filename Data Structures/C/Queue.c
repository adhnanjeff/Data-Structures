#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

typedef struct Queue Queue;

void init(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int is_empty(Queue* queue) {
    return queue->front == -1 && queue->rear == -1;
}

int is_full(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue* queue, int item) {
    if (!is_full(queue)) {
        if (is_empty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->arr[queue->rear] = item;
    } else {
        printf("Queue is full\n");
    }
}

int dequeue(Queue* queue) {
    int item = -1;
    if (!is_empty(queue)) {
        item = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            init(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
    } else {
        printf("Queue is empty\n");
    }
    return item;
}

int front(Queue* queue) {
    if (!is_empty(queue)) {
        return queue->arr[queue->front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

int main() {
    Queue queue;
    init(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(&queue));

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    printf("Front element after dequeues: %d\n", front(&queue));

    return 0;
}
