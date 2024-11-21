class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> uniqueTrees(n+1,vector<TreeNode*>());
        uniqueTrees[0].push_back(nullptr);
        uniqueTrees[1].push_back(new TreeNode(1));
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                for(TreeNode* leftNode: uniqueTrees[j-1]){
                    TreeNode* topNode = new TreeNode(j);
                    topNode->left = copy(leftNode, 0);
                    for(auto it = uniqueTrees[i-j].begin()+1; it != uniqueTrees[i-j].end(); ++it){
                        TreeNode* curr = copy(topNode, 0);
                        curr->right = copy(*it, j);
                        uniqueTrees[i].push_back(curr);
                    }
                    topNode->right = copy(uniqueTrees[i-j][0], j);
                    uniqueTrees[i].push_back(topNode);
                }
            }
        }
        return uniqueTrees[n];
    }
    TreeNode* copy(TreeNode* root, int add){
        if(!root)    return nullptr;
        stack<TreeNode*> st, st2;
        st.push(root);
        TreeNode* ret = new TreeNode(root->val + add);
        st2.push(ret);
        while(!st.empty()){
            TreeNode* curr = st2.top(), *origin = st.top();
            st.pop();
            st2.pop();
            if(origin->right){
                curr->right = new TreeNode(origin->right->val + add);
                st2.push(curr->right);
                st.push(origin->right);
            }
            if(origin->left){
                curr->left = new TreeNode(origin->left->val + add);
                st2.push(curr->left);
                st.push(origin->left);
            }
        }
        return ret;
    }
    vector<TreeNode*> nodes;
};