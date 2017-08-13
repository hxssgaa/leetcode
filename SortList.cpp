//Sort List
/*
	此题我认为没有意义，如果采用merge sort，那么空间复杂度有可能就为O(N)
	而O(N)则可以直接通过新建链表的方法来简便解决，完全没必要搞那么复杂
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode *tail = head;
	while (tail->next != NULL) tail = tail->next;
	return sortList(head, tail);
}