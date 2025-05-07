#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    int move;
    struct Node *prev, *next;
} Node;

int main(void) {
    int n;
    scanf("%d", &n);

    Node *head = NULL, *tail = NULL;
    for (int i = 1; i <= n; i++) {
        Node *node = (Node *) malloc(sizeof(Node));
        int m;
        scanf("%d", &m);
        node->id = i;
        node->move = m;
        if (!head) {
            head = tail = node;
            node->next = node->prev = node;
        } else {
            node->prev = tail;
            node->next = head;
            tail->next = node;
            head->prev = node;
            tail = node;
        }
    }

    Node *cur = head;
    for (int i = 0; i < n; i++) {
        int step = cur->move;
        printf("%d", cur->id);
        if (i < n - 1) printf(" ");

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        Node *temp = cur;

        if (step > 0) {
            cur = cur->next;
            for (int j = 1; j < step; j++) cur = cur->next;
        } else {
            cur = cur->prev;
            for (int j = 1; j < -step; j++) cur = cur->prev;
        }

        free(temp);
    }

    return 0;
}
