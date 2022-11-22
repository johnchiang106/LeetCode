class Solution {
public:
    int ans = -10000;
    int maxPathSum(TreeNode* root) {
        return max(ans,helper(root));
    }
    int helper(TreeNode* root) {
        if(!root)    return -10000;
        int maxL = helper(root->left);
        int maxR = helper(root->right);
        ans = max({ans, root->val, root->val+maxL+maxR, root->val+max(maxL,maxR)});
        return max(root->val, root->val+max(maxL,maxR));
    }
};