struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
	这个题请打起5星注意 ****** :

	这个题考察了dfs的bottom-up用法，传统的dfs只能计算
	child-parent的路径，但没有办法计算兄弟之间的路径权值，那么如何去计算呢？
	这里用到了一个辅助变量sum，该sum在遍历的过程中等于左右权值的最大值再加上节点的值
	而该函数返回的是dfs的child-parent的最大值，这样就可以完成dfs的路径.

	一定要理解这种在dfs过程中更新辅助变量的bottom-up思想
 */
int res = INT_MIN;
int dfs(TreeNode *root) {
    if (root == NULL) return 0;
    int left = max(0, dfs(root->left));
    int right = max(0, dfs(root->right));
    res = max(res, root->val + left + right);
    return max(left, right) + root->val;
}

int maxPathSum(TreeNode* root) {
    dfs(root);
    return res;
}