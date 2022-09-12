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
private:
    int low, high;
public:
    TreeNode* trimBST(TreeNode* root, int l, int h) {
        low = l;
        high = h;
        return helper(root);
    }
    TreeNode* helper(TreeNode* root){
        if(!root)   return NULL;
        if(root->val >= low && root->val <= high){
            if(root->left)  root->left = helper(root->left);
            if(root->right)  root->right = helper(root->right);
            return root;
        }
        if(root->left){
            root->left = helper(root->left);
            if(root->left)  return root->left;
        }
        if(root->right){
            root->right = helper(root->right);
            if(root->right)  return root->right;
        }
        return NULL;
    }
};