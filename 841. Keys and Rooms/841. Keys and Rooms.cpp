/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)   return 0;
        int ans = 0;
        
        stack<pair<TreeNode*,char>> st;
        vector<int> path;
        st.push({root,0});
        
        TreeNode* cur;
        
        while(!st.empty()){
            cur = st.top().first;
            char& time = st.top().second;
            
            if(time == 0){
                long long sum = 0;
                path.push_back(cur->val);
                for(int i = path.size()-1; i >= 0; --i){
                    sum += path[i];
                    if(sum == targetSum)    ++ans;
                }
                
                if(cur->left){
                    ++time;
                    st.push({cur->left,0});
                }
                else if(cur->right){
                    time = 2;
                    st.push({cur->right,0});
                }
                else{
                    st.pop();
                    path.pop_back();
                }
            }
            else if(cur->right && time == 1){
                ++time;
                st.push({cur->right,0});
            }
            else{
                st.pop();
                path.pop_back();
            }
        }
        
        return ans;
    }
};