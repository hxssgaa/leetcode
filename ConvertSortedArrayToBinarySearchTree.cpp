
struct TreeNode {
 	int val;
	TreeNode *left;
 	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//1 2 3 ->
/*
非常经典的利用中序遍历将排序好的数组转换为BST的方法，其中要注意
数组必须下标从1开始计算，因此可以在数组中首位元素添加一个元素来解决。
 */
TreeNode *inorder(vector<int>& nums, int root, int &index) {
	if (root >= nums.size()) return NULL;
	TreeNode *left = inorder(nums, root * 2, index);
	TreeNode *r = new TreeNode(nums[index++]);
	TreeNode *right = inorder(nums, root * 2 + 1, index);
	r->left = left;
	r->right = right;
	return r;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int index = 1;
    nums.insert(nums.begin(), 0);
	return inorder(nums, 1, index);
}