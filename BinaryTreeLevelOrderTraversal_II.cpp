

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 一定要注意细节
 */
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>>res;
	if (root == NULL) return res;
	queue<TreeNode*> q;
	q.push(root);
	vector<int> v;
	while (!q.empty()) {
		v.clear();
		int N = q.size();
		for (int i = 0; i < N; i++) {
			TreeNode *node = q.front();
			q.pop();
			v.push_back(node->val);
			if (node->left != NULL) q.push(node->left);
			if (node->right != NULL) q.push(node->right);
		}
		res.insert(res.begin(), v);
	}
	return res;
}