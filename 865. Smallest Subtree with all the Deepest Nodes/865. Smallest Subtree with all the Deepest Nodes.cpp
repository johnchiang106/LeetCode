class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)   return nullptr;
        if(depth(root->left) == depth(root->right))
            return root;
        if(depth(root->left) > depth(root->right))
            return subtreeWithAllDeepest(root->left);
        else
            return subtreeWithAllDeepest(root->right);
    }
private:
    int depth(TreeNode* root){
        // if(!root->left && !root->right) return 1;
        // if(root->left && root->right)
        //     return 1 + max(depth(root->left),depth(root->right));
        // if(root->left)
        //     return 1 + depth(root->left);
        // else
        //     return 1 + depth(root->right);
        if(!root)   return 0;
        return 1 + max(depth(root->left),depth(root->right));
    }
};