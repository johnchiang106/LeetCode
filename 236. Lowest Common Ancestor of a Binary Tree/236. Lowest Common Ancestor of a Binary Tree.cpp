/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)  return root;
        vector<pair<TreeNode*,char>> path;
        vector<TreeNode*> ppath, qpath;
        bool findp = false, findq = false;
        path.push_back({root,0});
        TreeNode* cur = root;
        while(!findp || !findq){
            if(path.back().second == 0){
                path.back().second = 1;
                if(cur->left)  path.push_back({cur->left,0});
            }
            else if(path.back().second == 1 && cur->right){
                path.back().second = 2;
                path.push_back({cur->right,0});
            }
            else    path.pop_back();
            
            cur = path.back().first;
            if(!findp && cur == p){
                for(auto n: path)   ppath.push_back(n.first);
                ppath.push_back(cur);
                findp = true;
            }
            else if(!findq && cur == q){
                for(auto n: path)   qpath.push_back(n.first);
                qpath.push_back(cur);
                findq = true;
            }
        }
        
        for(int i = 1; i < ppath.size() && i < qpath.size(); i++)
            if(ppath[i] != qpath[i])    return ppath[i-1];
        return ppath.back();
    }
};