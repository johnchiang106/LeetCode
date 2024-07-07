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
void dfs(TreeNode* root, stack<TreeNode*>& st){
    if(!root)   return;
    if(root->left)
        dfs(root->left, st);
    st.push(root);
    if(root->right)
        dfs(root->right, st);
    return;
}
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> st;
        dfs(root, st);
        int last = 0;
        while(!st.empty()){
            st.top()->val += last;
            last = st.top()->val;
            st.pop();
        }
        return root;
    }
};