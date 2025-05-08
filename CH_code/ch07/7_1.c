//원형 연결 리스트의 처음에 삽입


/*
ListNode* insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode *) malloc(sizeof(ListNode));
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
*/
