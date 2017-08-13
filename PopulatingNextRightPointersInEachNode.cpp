//117. Populating Next Right Pointers in Each Node II My Submissions Question

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//该方法同时使用I 与 II问题的解法，该binary tree可以是任何binary tree
void connect(TreeLinkNode *root) {
	if (root == NULL) return;
	queue<TreeLinkNode* > q;
	q.push(root);
	while(!q.empty()) {
		int n = (int)q.size();
		TreeLinkNode *pre = NULL;
		for (int i = 0; i < n; i++) {
			TreeLinkNode *node = q.front();//queue的前面节点方法为front()
			q.pop();
			if (pre != NULL) {
				pre->next = node;
			}
			pre = node;
			if (node->left != NULL) q.push(node->left);
			if (node->right != NULL) q.push(node->right);
		}
		pre->next = NULL;
	}    
}