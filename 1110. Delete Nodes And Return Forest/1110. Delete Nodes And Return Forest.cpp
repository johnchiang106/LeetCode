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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st;
        for(int& num: to_delete)
            st.insert(num);
        helper(root, st, ans, st.count(root->val), false);
        return ans;
    }
private:
    void helper(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& result, bool delCurr, bool parent){
        bool keepCurr = !delCurr && !parent;
        if(keepCurr){
            result.push_back(root);
        }
        if(root->left){
            bool delLeft = st.count(root->left->val);
            helper(root->left, st, result, delLeft, !delCurr);
            if(delLeft){
                root->left = nullptr;
            }
        }
        if(root->right){
            bool delRight = st.count(root->right->val);
            helper(root->right, st, result, delRight, !delCurr);
            if(delRight){
                root->right = nullptr;
            }
        }
    }
};