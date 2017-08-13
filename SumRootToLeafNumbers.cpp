//Sum Root to Leaf Numbers
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum = 0;

void dfs(TreeNode *root, int cur) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL)
		sum += cur;
	cur = cur * 10 + root->val;
	dfs(root->left, cur);
	dfs(root->right, cur);
}

int sumNumbers(TreeNode* root) {
	dfs(root, 0);
	return sum;
}