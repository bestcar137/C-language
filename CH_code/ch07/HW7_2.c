//
// Created by bestc on 25. 5. 8.
//

/// 과제 7-2
/// 큐(Queue)?
/// 멀티 플레이 게임
/*

 1. 순환 연결 리스트의 노드를 나타내는 구조체:
 각 노드에는 '요소(데이터)'와 다음 'ListNode(링크)'에 대한 포인터가 포함

 2. 순환 연결 리스트 자체를 나타내는 구조체:
 목록의 헤드 역할을 하는 'ListNode'에 대한 단일 포인터가 포함

 3. 헤드 노드부터 시작하여 원형 연결 리스트를 반복하고 각 노드의 데이터를 출력하는 함수

 4. 순환 연결 목록의 시작 부분에 새 노드를 삽입하는 함수

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];

typedef struct ListNode {   // 노드 타입

    element data;
    struct ListNode *link;
} ListNode;


/// 마지막에 삽입. 큐(Queue)에서는 처음에 삽입 X?
ListNode *insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));


    /*
    if (node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    */

    strcpy(node->data, data);       // 원형 연결 리스트에서는 node->data = data;
                                    // 데이터 복사

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

/// 리스트의 모든 노드 해제
void free_list(ListNode *head) {
    if (head == NULL) return;
    ListNode *p = head->link;
    while (p != head) {
        ListNode *temp = p;
        p = p->link;
        free(temp);
    }
    free(head); // 마지막 노드 해제
}

/// 메인 함수
/// 원형 연결 리스트 테스트 프로그램
int main (void) {
    ListNode* head = NULL;

    // 원형 연결 리스트에 데이터 삽입
    // KIM, JUNG, LEE, CHOI, PARK
    // 출력 메시지: Current trun=
    head = insert_last(head, "KIM");
    head = insert_last(head, "JUNG");
    head = insert_last(head, "LEE");
    head = insert_last(head, "CHOI");
    head = insert_last(head, "PARK");

    // 리스트 순회 및 출력
    ListNode *p = head->link;
    for (int i = 0; i < 10; i++) {
        printf("Current turn=%s\n", p->data);
        p = p->link;
    }

    /// 메모리 해제
    free_list(head);
    return 0;
}

/// 한번 더 체크
/// 중요!!


