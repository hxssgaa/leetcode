//Insertion Sort List

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
	对于链表的插入排序，要注意几点，首先是temp链表头的使用，一定要会用，temp->next就是新的head
	这样大幅度减轻了代码的难度，第二是对于链表的插入排序需要两个辅助节点before与cur，分别指向
	cur的前一个元素以及当前链表元素，由于在插入的过程中cur以及before都会改变，因此一定要根据不同情况
	去更新cur与before，特别要小心特殊情况，比如空指针head、单个元素以及已经排序好的链表的情况
 */
ListNode* insertionSortList(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode *temp = new ListNode(0);
    temp->next = head;
    ListNode *cur = head->next;
    ListNode *before = head;
    while (cur != NULL) {
        temp->val = cur->val;
        ListNode *b = temp;
        while (b->next != cur && b->next->val <= cur->val) {
            b = b->next;
        }
        ListNode *next = cur->next;
        if (b->next != cur) {
            before->next = cur->next;
            cur->next = b->next;
            b->next = cur;
        } else {
            before = before->next;
        }
        cur = next;
    }
    return temp->next;  
}