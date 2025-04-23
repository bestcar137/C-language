#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10
#define NAME_LEN 100

typedef struct {
    char data[MAX_QUEUE_SIZE][NAME_LEN];
    int front, rear;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue *q) {
    return q->front == q->rear;
}

int is_full(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue *q, char *name) {
    if (is_full(q)) {
        printf("대기열이 가득 찼습니다.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    strcpy(q->data[q->rear], name);
}

void dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("대기열이 비어 있습니다.\n");
        return;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    strcpy(q->data[q->rear = (q->rear + 1) % MAX_QUEUE_SIZE], q->data[q->front]);
}

void display(Queue *q) {
    int i = q->front;
    if (is_empty(q)) {
        printf("\n");
        return;
    }
    do {
        i = (i + 1) % MAX_QUEUE_SIZE;
        printf("%s", q->data[i]);
        if (i != q->rear) printf(", ");
    } while (i != q->rear);
    printf("\n");
}

int main() {
    Queue q;
    init(&q);

    int command;
    char name[NAME_LEN];

    while (1) {
        if (scanf("%d", &command) != 1) break;
        if (command == 1) {
            scanf("%s", name);
            enqueue(&q, name);
        } else if (command == 2) {
            dequeue(&q);
        } else if (command == 3) {
            display(&q);
        } else if (command == 4) {
            break;
        }
    }
    return 0;
}
