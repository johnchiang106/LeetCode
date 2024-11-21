class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        for(int i = 0; i <= n; ++i)
            nodes.push_back(new TreeNode(i));
        int count = n;
        solve(1,n,0,n,ans);
        return ans;
    }
    void solve(int n1, int n2, int par, int& count, vector<TreeNode*>& ans){
        if(n1 > n2) return;
        for(int i = n1; i <= n2; ++i){
            printf("%i ", i);
            if(par < i) nodes[par]->right = nodes[i];
            else        nodes[par]->left = nodes[i];
            solve(n1, i-1, i, count, ans);
            solve(i+1, n2, i, count, ans);
            if(--count == 0){
                ans.push_back(copy(nodes[0]->right));
            }
            ++count;
            if(par < i) nodes[par]->right = nullptr;
            else        nodes[par]->left = nullptr;
        }
        printf("\n");
    }
    TreeNode* copy(TreeNode* root){
        if(!root)    return nullptr;
        stack<TreeNode*> st, st2;
        st.push(root);
        TreeNode* ret = new TreeNode(root->val);
        st2.push(ret);
        while(!st.empty()){
            TreeNode* curr = st2.top(), *origin = st.top();
            st.pop();
            st2.pop();
            if(origin->right){
                curr->right = new TreeNode(origin->right->val);
                st2.push(curr->right);
                st.push(origin->right);
            }
            if(origin->left){
                curr->left = new TreeNode(origin->left->val);
                st2.push(curr->left);
                st.push(origin->left);
            }
        }
        return ret;
    }
    vector<TreeNode*> nodes;
};