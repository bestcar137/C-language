#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType *q) {
    return q->front == q->rear;
}

int is_full(QueueType *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        printf("The queue is filled to capacity.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
    queue_print(q);
}

element dequeue(QueueType *q) {
    if (is_empty(q)) {
        printf("The queue has no items.\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    element item = q->data[q->front];
    queue_print(q);
    return item;
}

void queue_print(QueueType *q) {
    printf("QUEUE(front=%d,rear=%d)=", q->front, q->rear);
    if (is_empty(q)) {
        printf("\n");
        return;
    }
    int i = q->front;
    do {
        i = (i + 1) % MAX_QUEUE_SIZE;
        printf("%d|", q->data[i]);
    } while (i != q->rear);
    printf("\n");
}

int main(void) {
    QueueType queue;
    init_queue(&queue);

    enqueue(&queue, 40);
    enqueue(&queue, 30);
    enqueue(&queue, 20);
    enqueue(&queue, 10);
    enqueue(&queue, 99);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    return 0;
}
