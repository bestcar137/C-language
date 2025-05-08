#include <stdio.h>
#include <stdlib.h>

/// 과제 7-1

// 구조체 정의
typedef int element;

typedef struct ListNode {   // 노드 타입

    element data;
    struct ListNode *link;
} ListNode;

// 원형 연결 리스트의 처음에 삽입
ListNode *insert_first(ListNode *head, element data) {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
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

// 원형 연결 리스트의 끝에 삽입
ListNode *insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
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

// 리스트의 항목 출력하는 함수
// print_list
void print_list(ListNode *head) {
    if (head ==NULL) return;
    ListNode *p = head->link;
    do {
        printf("%d->", p->data);
        p=p->link;
    } while (p !=head->link);   // 한 바퀴 돌면 종료
}

// 메모리 해제 함수
// free_list
void free_list(ListNode *head) {
    if (head ==NULL) return;
    for (ListNode *p = head->link, *temp;p!=head; free(temp))
        temp = p, p = p->link;
    free(head);
}

// 리스트의 모든 항목을 순회하면 출력하는 함수
// main 함수
int main(void) {
    ListNode *head = NULL;

    head = insert_first(head,10);
    head = insert_last(head,20);
    head = insert_last(head,30);
    head = insert_last(head,40);

    print_list(head);   // 리스트 항목 출력
    free_list(head);    // 메모리 해제
    return 0;
}
