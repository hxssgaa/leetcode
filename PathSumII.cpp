//Path Sum II
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pathSum(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &vec) {
	if (root == NULL) return;
	sum -= root->val;
	path.push_back(root->val);
	if (sum == 0 && root->left == NULL && root->right == NULL) {
		vec.push_back(path);
	}
	pathSum(root->left, sum, path, vec);
	pathSum(root->right, sum, path, vec);
	path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> vec;
	vector<int> path;
	pathSum(root, sum, path, vec);
	return vec;
}