class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if(root)    st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top(), *temp = curr->left, *temp2 = curr->right;
            st.pop();
            curr->left = temp2, curr->right = temp;
            if(temp2)    st.push(temp2);
            if(temp)    st.push(temp);
        }
        return root;
    }
};