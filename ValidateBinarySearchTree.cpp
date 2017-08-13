struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root, long long minV, long long maxV) {
	if (root == NULL) return true;
	if (root->left != NULL && 
		((root->left->val >= root->val)||
		(root->left->val <= minV))) return false;
	if (root->right != NULL && 
		((root->right->val <= root->val)||
		(root->right->val >= maxV))) return false;
	return isValidBST(root->left, minV, root->val) 
		&& isValidBST(root->right, root->val, maxV);
}
bool isValidBST(TreeNode* root) {
	return isValidBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
}