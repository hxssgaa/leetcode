
/*
         1
        / \
       2   3
inorder: 2,1,3
postorder: 2,3,1
*/
//inorder: left center right,   postorder: left right center
    TreeNode* buildTree(int *inorder, int *postorder, int N) {
        if (N == 0 || inorder == NULL) return NULL;
        TreeNode *root = new TreeNode(postorder[N-1]);
        int mid;
        for (int i = 0; i < N; i++) {
            if (inorder[i] == root->val) {
                mid = i;
                break;
            }
        }
        root->left = buildTree(inorder, postorder, mid);
        root->right = buildTree(inorder+mid+1, postorder+mid, N-mid-1);
        return root;
    }

    TreeNode* buildTree(vector<int> inorder, vector<int> postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }
        return buildTree(&inorder[0], &postorder[0], inorder.size());
    }