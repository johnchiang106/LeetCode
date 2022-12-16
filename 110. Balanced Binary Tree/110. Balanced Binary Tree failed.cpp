class Solution {
public:
    bool isBalanced(TreeNode* root) {
        queue<TreeNode*> q;
        if(root)    q.push(root);
        bool sub = true;
        while(!q.empty() && sub){
            for(int i = q.size(); i > 0; --i){
                TreeNode* curr = q.front();
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
                if(!curr->left || !curr->right){
                    sub = false;
                }
                q.pop();
            }
        }
        while(!q.empty()){
            TreeNode* curr = q.front();
            if(curr->left || curr->right) return false;
            q.pop();
        }
        return true;
    }
};