#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void print_list(ListNode* head) {
    if (head == NULL) return;
    ListNode* p = head->link;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head->link);
}

void free_list(ListNode* head) {
    if (head == NULL) return;
    for (ListNode* p = head->link, *temp; p != head; free(temp))
        temp = p, p = p->link;
    free(head);
}

ListNode* insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data) {
    ListNode *node = (ListNode*) malloc(sizeof(ListNode));
    node->data = data;
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

int main(void) {
    ListNode* head = NULL;

    head = insert_first(head, 10);
    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);

    print_list(head);
    free_list(head);
    return 0;
}
