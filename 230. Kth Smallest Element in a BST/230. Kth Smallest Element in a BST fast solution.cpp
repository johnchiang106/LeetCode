class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
        if(!root)   return 0;
        int x = kthSmallest(root->left, k);
        if(k == 0)   return x;
        if(--k == 0) return root->val;
        return kthSmallest(root->right, k);
    }
};