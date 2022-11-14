class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)   return nullptr;
        if(depth(root->left) == depth(root->right))
            return root;
        if(depth(root->left) > depth(root->right))
            return subtreeWithAllDeepest(root->left);
        else
            return subtreeWithAllDeepest(root->right);
    }
private:
    int depth(TreeNode* root){
        if(!root)   return 0;
        if(record.find(root) != record.end()){
            return record[root];
        }
        else{
            int d = 1 + max(depth(root->left),depth(root->right));
            record.insert({root,d});
            return d;
        }
    }
    unordered_map<TreeNode*,int> record;
};