class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root)    q.push(root);
        while(!q.empty()){
            vector<int> currLevel(q.size(), 0);
            for(auto& num: currLevel){
                TreeNode* curr = q.front();
                num = curr->val;
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
                q.pop();
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};