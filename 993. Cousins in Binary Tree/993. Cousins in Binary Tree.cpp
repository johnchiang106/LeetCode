class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* parent = nullptr;
        while(!parent){
            for(int i = q.size(); i > 0; --i){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    if((curr->left->val == x || curr->left->val == y)){
                        if(parent)    return parent != curr;
                        parent = curr;
                    }
                    q.push(curr->left);
                }
                if(curr->right){
                    if((curr->right->val == x || curr->right->val == y)){
                        if(parent)    return parent != curr;
                        parent = curr;
                    }
                    q.push(curr->right);
                }
            }
        }
        return false;
    }
};