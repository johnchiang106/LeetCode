class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        if(root)    q.push(root);
        while(!q.empty()){
            for(auto i = q.size(); i > 0; --i){
                TreeNode* curr = q.front();
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
                q.pop();
            }
            ++ans;
        }
        return ans;
    }
};