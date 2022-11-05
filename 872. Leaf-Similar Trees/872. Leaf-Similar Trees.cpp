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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<char> vec;
        stack<TreeNode*> st;
        st.push(root1);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            if(temp->right)
                st.push({temp->right});
            if(temp->left)
                st.push({temp->left});
            else if(!temp->right)
                vec.push_back(temp->val);
        }
        int i = 0;
        st.push(root2);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            if(temp->right)
                st.push({temp->right});
            if(temp->left)
                st.push({temp->left});
            else if(!temp->right && temp->val != vec[i++]){
                return false;
            }
        }
        return i == vec.size();
    }
};