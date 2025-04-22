#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef int element;

typedef struct {
    element data[MAX_SIZE];
    int front;
    int rear;
    int count;
    int capacity;
} CircularQueue;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(CircularQueue *q, int size) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    q->capacity = size;
}

int is_full(CircularQueue *q) {
    return q->count == q->capacity;
}

int is_empty(CircularQueue *q) {
    return q->count == 0;
}

void enqueue(CircularQueue *q, element item) {
    if (is_full(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % q->capacity;
    q->count++;
    printf("%d\n", item);
}

element dequeue(CircularQueue *q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return 0;
    }
    element item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->count--;
    return item;
}

int main(void) {
    int size;
    scanf("%d", &size);

    CircularQueue q;
    init(&q, size);

    for (int i = 1; i <= size + 1; i++) {
        enqueue(&q, i);
    }

    for (int i = 0; i <= size; i++) {
        printf("%d\n", dequeue(&q));
    }

    return 0;
}
