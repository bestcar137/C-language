#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
} element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} Li;

Li *insert_first(Li *head, element value) {
    Li *p = (Li *) malloc(sizeof(Li));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(Li *head) {
    for (Li *p = head; p != NULL; p = p->link)
        printf("%s->", p->data.name);
    printf("NULL\n");
}

int main(void) {
    Li *head = NULL;
    element data;

    strcpy(data.name, "DCU");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "IS");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "DAEGU");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "CATHOLIC");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "UNIVERSITY");
    head = insert_first(head, data);
    print_list(head);

    return 0;
}
