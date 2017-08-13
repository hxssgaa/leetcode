//此题我觉得没有必要非要O(1)的空间复杂度，毕竟时间复杂度被简洁的阅读才是王道，这种解法利用了backtracking
void reorderList(ListNode* &head, ListNode *tail, bool &flag) {
    if (head == NULL || tail == NULL || tail->next == NULL) return;
    reorderList(head, tail->next, flag);
    if (head == tail || head->next == NULL) flag = true;
    if (flag) return;
    tail->next->next = head->next;
    head->next = tail->next;
    head = tail->next->next;
    tail->next = NULL;
}
void reorderList(ListNode* head) {
    bool flag = false;
    reorderList(head, head, flag);
}
