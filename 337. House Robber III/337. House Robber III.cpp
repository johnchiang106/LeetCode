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
    int rob(TreeNode* root) {
        if(!root)   return 0;
        return helper(root,true);
    }
private:
    map<pair<TreeNode*,bool>,int> m;
    
    int helper(TreeNode* root, bool allow){
        if(!root->left && !root->right)
            return allow ? root->val : 0;
        if(m.find({root,allow}) != m.end())
            return m[{root,allow}];
        
        int pass = 0;
        if(allow){
            int enter = root->val;
            
            if(root->left){
                enter += helper(root->left,false);
                pass += helper(root->left,true);
            }
            if(root->right){
                enter += helper(root->right,false);
                pass += helper(root->right,true);
            }
            m.insert({{root,allow},max(enter,pass)});
            return max(enter,pass);
        }
        else{
            if(root->left)  pass += helper(root->left,true);
            if(root->right) pass += helper(root->right,true);
            m.insert({{root,allow},pass});
            return pass;
        }
    }
};