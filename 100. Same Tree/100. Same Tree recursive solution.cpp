class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;
        if(q->val!=p->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};