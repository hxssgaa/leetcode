bool hasCycle(ListNode *head) {
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast != NULL && fast->next && fast->next->next != NULL) {
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
		if (fast == slow) return true;
	}
	return false;
}