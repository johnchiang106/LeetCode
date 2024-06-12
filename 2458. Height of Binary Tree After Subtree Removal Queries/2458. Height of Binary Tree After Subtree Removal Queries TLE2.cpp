class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        const int m = queries.size();
        begin = new TreeNode(0);
        parent[root->val] = begin;
        int longest = longestPathLength(root)-1;
        findPath(root);

        vector<int> ans(m, longest);
        for(int i = 0; i < m; ++i){
            if(cache.find(queries[i]) != cache.end()){
                ans[i] = findNewHeight(queries[i],0);
                cache[queries[i]] = ans[i];
            }
        }
        return ans;
    }
    int longestPathLength(TreeNode* root){
        if(!root)   return 0;
        int l = 0, r = 0;
        if(root->left){
            l = longestPathLength(root->left);
            parent[root->left->val] = root;
        }
        if(root->right){
            r = longestPathLength(root->right);
            parent[root->right->val] = root;
        }
        mp[root] = {l, r};
        return max(l, r) + 1;
    }
    void findPath(TreeNode* root){
        if(!root)   return;
        pair<int,int> children = mp[root];
        if(children.first == children.second)
            return;
        root = children.first > children.second ? root->left : root->right;
        // int h = findNewHeight(root->val, 0);
        // if(h != -1)
            cache[root->val] = -2;
        findPath(root);
        return;
    }
    int findNewHeight(int curr, int length){
        if(drop[curr].find(length) != drop[curr].end())
            return drop[curr][length];
        TreeNode* par = parent[curr];
        if(par == begin){
            return length-1;
        }
        if(par->left && par->left->val == curr && mp[par].first > mp[par].second){
            int h = findNewHeight(par->val, max(length, mp[par].second)+1);
            drop[curr][length] = h;
            return h;
        }
        if(par->right && par->right->val == curr && mp[par].second > mp[par].first){
            int h = findNewHeight(par->val, max(length, mp[par].first)+1);
            drop[curr][length] = h;
            return h;
        }
        return -1;
    }
private:
    TreeNode* begin;
    unordered_map<int,int> cache;
    unordered_map<int, unordered_map<int, int>> drop;
    unordered_map<TreeNode*, pair<int,int>> mp;
    unordered_map<int, TreeNode*> parent;
};