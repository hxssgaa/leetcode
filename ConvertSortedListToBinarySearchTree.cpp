
struct TreeNode {
 	int val;
	TreeNode *left;
 	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//道理其实与上一题是一样的，不过这里由于用了ListNode，需要知道长度N，并且函数必须存放指针的引用才行
TreeNode *inorder(ListNode* &head, int n, int root) {
	if (root >= n || head == NULL) return NULL;
	TreeNode *left = inorder(nums, n, root * 2);
	TreeNode *r = new TreeNode(head->val);
	head = head->next;
	TreeNode *right = inorder(nums, n, root * 2 + 1);
	r->left = left;
	r->right = right;
	return r;
}

TreeNode* sortedArrayToBST(ListNode* head) {
	int n = 0;
	ListNode *cur = head;
	while (cur != NULL) {
		cur = cur->next;
		n++;
	}
	return inorder(head, n, 1);
}