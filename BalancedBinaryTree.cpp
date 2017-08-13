	
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
	这个题不可轻易用height map去优化，因为即使用height map，查找和插入的过程也没有想象中那么快。
*/

int solveHeight(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(solveHeight(root->left), solveHeight(root->right));
}

bool isBalanced(TreeNode* root) {
    if (root == NULL) return true;
    return abs(solveHeight(root->left)-solveHeight(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
}