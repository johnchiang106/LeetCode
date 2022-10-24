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
    TreeNode* convertBST(TreeNode* root) {
        if(!root)   return root;
        stack<TreeNode*> st;
        stack<pair<TreeNode*,bool>> s2;
        s2.push({root,true});
        while(!s2.empty()){
            pair<TreeNode*,bool>& temp = s2.top();
            if(temp.second){
                temp.second = false;
                if(temp.first->left)
                    s2.push({temp.first->left,true});
            }
            else{
                st.push(temp.first);
                s2.pop();
                if(temp.first->right)
                    s2.push({temp.first->right,true});
            }
        }
        int last = 0;
        while(!st.empty()){
            st.top()->val += last;
            last = st.top()->val;
            st.pop();
        }
        return root;
    }
};