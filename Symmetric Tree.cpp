/*
	Symmetric Tree

	Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

	这个题实际上是很简单的递归题，题目要求镜像tree，我们可以将其分解成
	一个节点的左孩子节点与另一个节点的右孩子节点相比较的问题。
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
    	1
  	   / \
  	  2   2
     / \ / \
    3  4 4  3
   / \/ \/\ /\
  1           1
*/
bool isSymmetric(TreeNode* a, TreeNode* b) {
	if (a == NULL || b == NULL)
		return a==b;
	if (a->val != b->val)
		return false;
	return isSymmetric(a->left,b->right) && isSymmetric(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
	return root==null || isSymmetric(root->left, root->right);
}