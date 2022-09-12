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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        
        stack<pair<TreeNode*,char>> st;
        vector<int> path;
        st.push({root,0});
        
        TreeNode* cur;
        int sum = 0;
        
        while(!st.empty()){
            cur = st.top().first;
            char& time = st.top().second;
            
            if(time == 0){
                sum += cur->val;
                path.push_back(cur->val);
                
                if(cur->left){
                    time++;
                    st.push({cur->left,0});
                }
                else if(cur->right){
                    time = 2;
                    st.push({cur->right,0});
                }
                else{
                    if(sum == targetSum)
                        ans.push_back(path);
                    sum -= cur->val;
                    st.pop();
                    path.pop_back();
                }
            }
            else if(cur->right && time == 1){
                time++;
                st.push({cur->right,0});
            }
            else{
                sum -= cur->val;
                st.pop();
                path.pop_back();
            }
        }
        
        return ans;
    }
};