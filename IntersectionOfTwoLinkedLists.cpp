ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL) return NULL;
	int n1 = 0;
	int n2 = 0;
	ListNode *curA = headA;
	ListNode *curB = headB;
	while (curA->next != NULL) {
		curA = curA->next;
		n1++;
	}
	while (curB->next != NULL) {
		curB = curB->next;
		n2++;
	}
	if (curA != curB) return NULL;
	int offset = max(n1, n2) - min(n1, n2);
	ListNode *longNode = n1 >= n2 ? headA : headB;
	ListNode *shortNode = n1 < n2 ? headA : headB;
	for (int i = 0; i < offset; i++) 
		longNode = longNode->next;
	while (longNode != shortNode) {
		longNode = longNode->next;
		shortNode = shortNode->next;
	}
	return longNode;
}