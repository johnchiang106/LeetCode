class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        const int m = queries.size();
        vector<int> ans(m, 0);
        unordered_map<TreeNode*, int> mp;
        longestPath(root, mp);

        for(int i = 0; i < m; ++i){
            bool found = false;
            ans[i] = findNewHeight(root, queries[i], found, mp)-1;
        }
        return ans;
    }
    int longestPath(TreeNode* root, unordered_map<TreeNode*, int>& mp){
        if(!root)   return 0;
        int l = longestPath(root->left, mp), r = longestPath(root->right, mp);
        mp[root] = max(l, r) + 1;
        return max(l, r) + 1;
    }
    int findNewHeight(TreeNode* root, const int& remove, bool& found, unordered_map<TreeNode*, int>& mp){
        if(!root)   return 0;
        int l, r;
        if(!root->left) l = 0;
        else if(root->left->val == remove){
            l = 0;
            found = true;
        }
        else    l = found ? mp[root->left] : findNewHeight(root->left, remove, found, mp);
        if(!root->right) r = 0;
        else if(root->right->val == remove){
            r = 0;
            found = true;
        }
        else    r = found ? mp[root->right] : findNewHeight(root->right, remove, found, mp);
        return max(l, r) + 1;
    }
};