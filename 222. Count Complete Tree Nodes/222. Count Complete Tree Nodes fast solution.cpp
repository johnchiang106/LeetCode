class Solution {
    public: 
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int res = 0, leftL = 0;
        for(TreeNode* p = root->left; p; p = p->left)
            ++leftL;
        while(leftL >= 0){
            int rightL = 0;
            for(TreeNode* p = root->right; p; p = p->left)
                ++rightL;
            res += 1<<rightL;
            root = (leftL == rightL) ? root->right : root->left;
            --leftL;
        }
        return res;
    }
};