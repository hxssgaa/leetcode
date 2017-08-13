/*
	这个算法要求背得，非常有意思，先序遍历就是
	利用stack，然后类似于层序遍历一样先push顶端元素的右边元素，再push左边元素，这样就
	pop的时候就会先出左边的元素，注意后续遍历就是先序遍历的相反序列
	其实更简单的想法就是想"中左右"，因此先访问中，再push右和左即左右
 */
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode *> s;
    if (root==NULL) return result;
    s.push(root);
    while (!s.empty()) {
        TreeNode *t = s.top();
        result.push_back(t->val);
        s.pop();
        if (t->right!=NULL) {
            s.push(t->right);
        }
        if (t->left!=NULL) {
            s.push(t->left);
        }
    }
    return result;
}

//后续遍历是“左右中"，因此我们可以利用“中右左”的反序序列来构建后序序列
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode *> s;
    if (root==NULL) return result;
    s.push(root);
    while (!s.empty()) {
        TreeNode *t = s.top();
        result.push_back(t->val);
        s.pop();
        if (t->left!=NULL) {
            s.push(t->left);
        }
        if (t->right!=NULL) {
            s.push(t->right);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}