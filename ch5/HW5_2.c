#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef int element;

typedef struct {
    element data[MAX];
    int front, rear;
    int count;
    int capacity;
} CircularQueue;

void init(CircularQueue *q, int size) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    q->capacity = size;
}

int is_empty(CircularQueue *q) {
    return q->count == 0;
}

int is_full(CircularQueue *q) {
    return q->count == q->capacity;
}

void enqueue(CircularQueue *q, element item) {
    if (is_full(q)) return;
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % q->capacity;
    q->count++;
}

element dequeue(CircularQueue *q) {
    if (is_empty(q)) return -1;
    element item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->count--;
    return item;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    CircularQueue q;
    init(&q, n);

    for (int i = 1; i <= n; i++) enqueue(&q, i);

    while (!is_empty(&q)) {
        for (int i = 1; i < k; i++) {
            element temp = dequeue(&q);
            enqueue(&q, temp);
        }
        printf("%d", dequeue(&q));
        if (q.count > 0) printf(", ");
    }

    return 0;
}
