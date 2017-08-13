/*
	Binary Tree Inorder Traversal
	
	Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
	
	涉及算法: 树的中序非递归算法
	算法思路: 
	我们可以用一个stack<TreeNode*> 存放树的节点栈
	大体思路是先不断地push节点的左孩子节点，在没有左孩子的时候去push右孩子节点
	然后在push右孩子节点的过程中pop节点
	但是我们注意到在pop的过程中类似于：
		   1
	  	  /
	 	 2
		/
   	   3
   	的情形在pop 3的时候我们又在2的节点中push了3，造成死循环，解决的办法是
   	多一个prev指针，当prev==top的时候我们不能push该节点的左节点.
   	当然我们在push右孩子节点的时候也要更新prev变为s pop之后的top节点.	
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	if (root == NULL) return res;
	stack<TreeNode *> s;
	TreeNode *prev = NULL;
	s.push(root);
	while (!s.empty()) {
		TreeNode *top = s.top();
		if (top->left != NULL && prev != top) {
			s.push(top->left);
			prev = top;
		}
		else {
			res.push_back(top->val);
			s.pop();
			if (s.size() > 0)
				prev = s.top();
			if (top->right != NULL) {
				s.push(top->right);
			}
		}
	}
	return res;
}