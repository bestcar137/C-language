#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef char element;

typedef struct
{
    element data[SIZE];
    int front;
    int rear;
} QueueType;

void init(QueueType *Q)
{
    Q->front = -1;
    Q->rear = -1;
}

int is_empty(QueueType *Q)
{
    return Q->front == Q->rear;
}

int is_full(QueueType *Q)
{
    return Q->rear == SIZE - 1;
}

void enqueue(QueueType *Q, element e)
{
    if (is_full(Q))
        exit(1);
    Q->data[++(Q->rear)] = e;
}

element dequeue(QueueType *Q)
{
    if (is_empty(Q))
        exit(1);
    return Q->data[++(Q->front)];
}

void print(QueueType *Q)
{
    printf("Front Pos : %d, Rear Pos : %d\n", Q->front, Q->rear);
    for (int i = Q->front + 1; i <= Q->rear; i++)
        printf("[%c] ", Q->data[i]);
    printf("\n");
}

int main()
{
    QueueType Q;
    init(&Q);

    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');
    print(&Q);
    printf("[%c] \n", dequeue(&Q));
}
