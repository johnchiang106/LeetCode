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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        
        int cur_level = 0;
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            if(cur_level != q.front().second){
                if(cur_level > 0 && cur_level % 2 == 0)
                    reverse(ans.back().begin(), ans.back().end());
                ans.push_back(vector<int>());
                ++cur_level;
            }
            if(temp->left)  q.push({temp->left,cur_level+1});
            if(temp->right)   q.push({temp->right,cur_level+1});
            ans.back().push_back(temp->val);
            q.pop();
        }
        if(cur_level % 2 == 0)  reverse(ans.back().begin(), ans.back().end());
        return ans;
    }
};