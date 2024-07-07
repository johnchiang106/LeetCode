class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root)   return false;
        queue<TreeNode*> q;
        q.push(root);
        bool hasNull = false;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr){
                if(hasNull)    return false;
                q.push(curr->left);
                q.push(curr->right);
            }
            else    hasNull = true;
        }
        return true;
    }
};