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
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            ++ans;
            int num = q.size();
            for(int i = 0; i < num; ++i){
                TreeNode* curr = q.front();
                if(!curr->left && !curr->right)    return ans;
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
                q.pop();
            }
        }
        return ans;
    }
};