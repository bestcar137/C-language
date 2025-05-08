#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} Li;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

Li* insert_first(Li *head, int value)
{
    Li *p = (Li *)malloc(sizeof(Li));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

Li* insert(Li *head, Li *pre, element value)
{
    Li *p = (Li *)malloc(sizeof(Li));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

Li* delete_first(Li *head)
{
    Li *removed;
    if (head == NULL) return NULL;
    removed = head;
    head = head->link;
    free(removed);
    return head;
}

Li* delete(Li *head, Li *pre)
{
    Li *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(Li *head)
{
    for (Li *p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

int main(void)
{
    Li *head = NULL;

    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }

    for (int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }

    return 0;
}
