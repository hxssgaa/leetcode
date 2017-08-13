/*
	Linked List Cycle II

	Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 */

ListNode *detectCycle(ListNode *head) {
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast	!= NULL && fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			while (true) {
				if (fast == head) return fast;
			    fast = fast->next;
				head = head->next;
			}
		}
	} 
	return NULL;
}