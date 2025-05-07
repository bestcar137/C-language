#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    if (node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }

    strcpy(node->data, data);
    if (head == NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

void free_list(ListNode *head) {
    if (head == NULL) return;
    ListNode *p = head->link;
    ListNode *temp;
    while (p != head) {
        temp = p;
        p = p->link;
        free(temp);
    }
    free(head);
}

int main(void) {
    ListNode *head = NULL;

    head = insert_last(head, "KIM");
    head = insert_last(head, "PARK");
    head = insert_last(head, "CHOI");

    ListNode *p = head->link;
    for (int i = 0; i < 10; i++) {
        printf("현재 차례 = %s\n", p->data);
        p = p->link;
    }

    free_list(head);
    return 0;
}
