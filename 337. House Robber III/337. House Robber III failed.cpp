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
    int helper(TreeNode* root, bool allow){
        if(!root->left && !root->right){
            return allow ? root->val : 0;
        }
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
            return max(enter,pass);
        }
        else{
            if(root->left){
                pass += helper(root->left,true);
            }
            if(root->right){
                pass += helper(root->right,true);
            }
            return pass;
        }
    }
    
    int rob(TreeNode* root) {
        if(!root)   return 0;
        return helper(root,true);
    }
};