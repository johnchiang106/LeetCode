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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode;
        if(n == 0)    return root;
        root->val = preorder.front();
        stack<TreeNode*> st;
        st.push(root);
        for(int i = 1; i < n; ++i){
            int num = preorder[i];
            TreeNode* newNode = new TreeNode(num), *lastNode = st.top();
            if(num < lastNode->val){
                lastNode->left = newNode;
            }
            else{
                while(!st.empty() && num > st.top()->val){
                    lastNode = st.top();
                    st.pop();
                }
                lastNode->right = newNode;
            }
            st.push(newNode);
        }
        return root;
    }
};