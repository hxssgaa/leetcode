struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (m < 1) return NULL;
	if (head == NULL) return NULL;
	int curIndex = 1;
	ListNode temp(0);
	temp.next = head;
	ListNode *start = NULL;
	ListNode *cur = head;
	while (curIndex < m) {
		cur = cur->next;
		curIndex++;
		if (start == NULL) start = head;
		else start = start->next;
	}
	if (start == NULL) start = &temp;
	ListNode *prev = cur;
	cur = cur->next;
	while (curIndex < n) {
		ListNode *next = start->next;
		start->next = cur;
		prev->next = cur->next;
		cur->next = next;
		cur = prev->next;
		curIndex++;
	}
	return temp.next;       
}