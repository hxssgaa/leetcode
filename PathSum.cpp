//Path Sum
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int sum) {
	if (root == NULL) return false;
	int remain = sum - root->val;
	if (remain == 0 && root->left == NULL && root->right == NULL) return true;
	return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
}