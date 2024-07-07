class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            if(curr->val == subRoot->val && identical(curr, subRoot))
                return true;
            st.pop();
            if(curr->right)   st.push(curr->right);
            if(curr->left)   st.push(curr->left);
        }
        return false;
    }
private:
    bool identical(TreeNode* r1, TreeNode* r2){
        stack<pair<TreeNode*,TreeNode*>> st;
        st.push({r1,r2});
        while(!st.empty()){
            TreeNode* t1 = st.top().first, *t2 = st.top().second;
            if((t1->val != t2->val) || (t1->left && !t2->left) || (!t1->left && t2->left)
             || (t1->right && !t2->right) || (!t1->right && t2->right))
                return false;
            st.pop();
            if(t1->right)   st.push({t1->right,t2->right});
            if(t1->left)   st.push({t1->left,t2->left});
        }
        return true;
    }
};