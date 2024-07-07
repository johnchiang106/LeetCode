class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root)    q.push(root);
        while(!q.empty()){
            TreeNode* f;
            for(int i = q.size(); i > 0; --i){
                f = q.front();
                if(f->left)  q.push(f->left);
                if(f->right)  q.push(f->right);
                q.pop();
            }
            ans.push_back(f->val);
        }
        return ans;
    }
};