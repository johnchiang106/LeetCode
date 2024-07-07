class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return NULL;
        stack<pair<TreeNode*,char>> st1, st2;
        st1.push({root,0});
        st2.push({root,0});
        findNode(st1, p);
        findNode(st2, q);
        while(!st1.empty() && !st2.empty()){
            if(st1.size() == st2.size()){
                if(st1.top().first == st2.top().first)
                    return st1.top().first;
                else{
                    st1.pop();
                    st2.pop();
                }
            }
            else if(st1.size() > st2.size())
                st1.pop();
            else
                st2.pop();
        }
        return NULL;
    }
private:
    void findNode(stack<pair<TreeNode*,char>>& path, TreeNode* target){
        while(!path.empty()){
            char& count = ++path.top().second;
            TreeNode* curr = path.top().first;
            if(count == 3)
                path.pop();
            else if(count == 1){
                if(curr == target)
                    break;
                if(curr->left)
                    path.push({curr->left,0});
            }
            else{
                if(curr->right)
                    path.push({curr->right,0});
                else    path.pop();
            }
        }
    }
};