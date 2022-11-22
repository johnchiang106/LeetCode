class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        makeStack(st, root);
        while(--k > 0)  st.pop();
        return st.top()->val;
    }
private:
    void makeStack(stack<TreeNode*>& st, TreeNode* root){
        if(root->right) makeStack(st, root->right);
        st.push(root);
        if(root->left) makeStack(st, root->left);
    }
};