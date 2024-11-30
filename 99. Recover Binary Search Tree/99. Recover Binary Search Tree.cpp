class Solution {
private:
    TreeNode* first, *second, *prev;
    void helper(TreeNode* root){
        if(!root)   return;
        helper(root->left);
        if(prev && prev->val >= root->val){
            if(!first)   first = prev;
            second = root;
        }
        prev = root;
        helper(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val, second->val);
    }
};