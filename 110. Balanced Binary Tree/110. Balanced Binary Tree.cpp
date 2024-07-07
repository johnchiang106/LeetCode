class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(depth(root) == -1)   return false;
        return true;
    }
private:
    int depth(TreeNode* root){
        if(!root)   return 0;
        int l = depth(root->left);
        if(l == -1) return -1;
        int r = depth(root->right);
        if(r == -1 || abs(l-r) > 1)    return -1;
        return max(l,r) + 1;
    }
};