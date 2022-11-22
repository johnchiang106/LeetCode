class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return NULL;
        TreeNode* curr = root;
        int t1 = p->val, t2 = q->val, &v = curr->val;
        while(true){
            if(t1 > v && t2 > v)    curr = curr->right;
            else if(t1 < v && t2 < v)    curr = curr->left;
            else    break;
            v = curr->val;
        }
        return curr;
    }
};