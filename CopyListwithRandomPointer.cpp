//Copy List with Random Pointer

unordered_map<int, RandomListNode*> m;

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL) return NULL;
	if (m.find(head->label) != m.end()) return m[head->label];
	RandomListNode *res = new RandomListNode(head->label);
	m[head->label] = res;
	res->next = copyRandomList(head->next);
	res->random = copyRandomList(head->random);
}