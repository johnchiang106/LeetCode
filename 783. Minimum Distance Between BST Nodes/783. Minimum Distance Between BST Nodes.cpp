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
    int getMinimumDifference(TreeNode* root) {
        int ans = 100000, p = -100000;
        stack<pair<TreeNode*,bool>> st;
        TreeNode* curr;
        st.push({root,true});
        
        while(!st.empty()){
            curr = st.top().first;
            bool& ftime = st.top().second;
            
            if(ftime && curr->left){
                st.push({curr->left,true});
                ftime = false;
            }
            else{
                if(curr->val - p < ans)
                    ans = curr->val - p;
                p = curr->val;
                st.pop();
                if(curr->right)
                    st.push({curr->right,true});
            }
        }
        return ans;
    }
};