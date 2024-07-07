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
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int level = 1, ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() == level){
            ans += level;
            for(int i = level-1; i >= 0; --i){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)  q.push(temp->left);
                else    return ans - i + q.size();
                if(temp->right)  q.push(temp->right);
                else    return ans - i + q.size();
            }
            level *= 2;
        }
        return ans + q.size();
    }
};