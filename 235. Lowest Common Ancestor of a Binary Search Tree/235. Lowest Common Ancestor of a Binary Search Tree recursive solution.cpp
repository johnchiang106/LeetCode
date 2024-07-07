class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return NULL;
        queue<TreeNode*> q1, q2;
        findNode(q1, root, p);
        findNode(q2, root, q);
        while(q1.size() > q2.size())
            q1.pop();
        while(q1.size() < q2.size())
            q2.pop();
        while(q1.front() != q2.front()){
            q1.pop(); q2.pop();
        }
        if(!q1.empty())
            return q1.front();
        return NULL;
    }
private:
    bool findNode(queue<TreeNode*>& path, TreeNode* root, TreeNode* target){
        if(root == target || 
            (root->left && findNode(path,root->left,target)) ||
            (root->right && findNode(path,root->right,target)) ){
            path.push(root);
            return true;
        }
        return false;
    }
};