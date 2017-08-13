struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
	Recover Binary Search Tree

	Two elements of a binary search tree (BST) are swapped by mistake.

	Recover the tree without changing its structure.

	解法：利用中序遍历得到遍历序列，找到两个位置不对的元素，swap它们即可
	一定要注意，不能swap多次，因为题目只是说有2个元素位置不对！！
 */

void inOrder(TreeNode *root, vector<TreeNode *> &res) {
	if (root == NULL) return;
	preOrder(root->left, res);
	res.push_back(root);
	preOrder(root->right, res);
}

//这里不能交换多次！！！
void recoverTree(TreeNode* root) {
	vector<TreeNode *> vec;
	preOrder(root, vec);
	if (vec.size() <= 1) return;
	int one = -1, two = -1;
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i]->val > vec[i+1]->val) {
			if (one == -1)
				one = i;
			else
				two = i;
		}
	}
	if (two == -1) swap(vec[one]->val, vec[one+1]->val);
	else swap(vec[one]->val, vec[two+1]->val);
}