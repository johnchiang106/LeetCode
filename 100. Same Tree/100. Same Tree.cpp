/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)    return true;
        if(!p || !q || p->val != q->val)  return false;
        stack<pair<TreeNode*,TreeNode*>> s;
        s.push({p,q});
        while(!s.empty()){
            TreeNode *t1 = s.top().first, *t2 = s.top().second;
            if(!t1 && !t2)    s.pop();
            else if(t1 && t2 && t1->val == t2->val){
                s.pop();
                s.push({t1->right,t2->right});
                s.push({t1->left,t2->left});
            }
            else    return false;
        }
        return true;
    }
};