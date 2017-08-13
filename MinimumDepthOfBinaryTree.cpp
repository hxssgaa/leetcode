//Definition for a binary tree node.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return 1;
	if (root->left == NULL && root->right != NULL) return 1 + minDepth(root->right);
	if (root->right == NULL && root->left != NULL) return 1 + minDepth(root->left);
	return 1+min(minDepth(root->left), minDepth(root->right));
}