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
    string tree2str(TreeNode* root) {
        string ans = "";
        helper(ans, root);
        return ans;
    }
    void helper(string& ans, TreeNode* node){
        ans += to_string(node->val);
        if(!node->left && !node->right) return;
        ans += '(';
        if(node->left){
            helper(ans, node->left);
        }
        ans += ')';
        if(node->right){
            ans += '(';
            helper(ans, node->right);
            ans += ')';
        }
    }
};