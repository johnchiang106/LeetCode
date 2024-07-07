class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 1;
        stack<pair<TreeNode*,int>> maxVal;
        maxVal.push({root,root->val});
        while(!maxVal.empty()){
            TreeNode* l = maxVal.top().first->left, *r = maxVal.top().first->right;
            int v = maxVal.top().second;
            maxVal.pop();
            if(r){
                if(r->val >= v){
                    ++ans;
                }
                maxVal.push({r,max(r->val,v)});
            }
            if(l){
                if(l->val >= v){
                    ++ans;
                }
                maxVal.push({l,max(l->val,v)});
            }
        }
        return ans;
    }
};