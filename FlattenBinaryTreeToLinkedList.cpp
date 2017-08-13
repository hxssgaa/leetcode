//Flatten Binary Tree to Linked List

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//此题注意并非root->left == NULL的时候就终止了，而是需要不断迭代到最后一个右节点为止.
//另外迭代的时候需要将root->left置为空
void flatten(TreeNode* root) {
	if (root == NULL) return;
	if (root->left != NULL) {
		TreeNode *left = root->left;
		while (left->right != NULL) {
			left = left->right;
		}
		left->right = root->right;
		root->right = root->left;
		root->left = NULL;
	}
	flatten(root->right);
}