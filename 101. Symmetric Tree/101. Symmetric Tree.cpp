class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        TreeNode* r1, *r2;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty()){
            r1 = q1.front(), r2 = q2.front();
            q1.pop(); q2.pop();
            if(!r1 && !r2)  continue;
            if(!r1 || !r2 || (r1->val != r2->val))
                return false;
            q1.push(r1->left); q1.push(r1->right);
            q2.push(r2->right); q2.push(r2->left);
        }
        return true;
    }
};