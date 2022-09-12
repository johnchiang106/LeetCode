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
    vector<TreeNode*> ordered;
    TreeNode* balanceBST(TreeNode* root) {
        orderElement(root);
        return arrToTree(0, ordered.size()-1);
    }
    void orderElement(TreeNode* node){
        stack<pair<TreeNode*,bool>> st;
        st.push({node,false});
        while(!st.empty()){
            TreeNode* cur = st.top().first;
            if(st.top().second){
                ordered.push_back(cur);
                st.pop();
            }
            else{
                if(cur->right){
                    st.top().first = cur->right;
                    st.push({cur,false});
                }
                if(cur->left){
                    st.top().second = true;
                    st.push({cur->left,false});
                }
                else{
                    ordered.push_back(cur);
                    st.pop();
                }
            }
        }
    }
    TreeNode* arrToTree(int start, int last){
        /*unsolved stack solution
        stack<pair<int,int>> st;
        st.push(start, last);
        while(!st.empty()){
            int s = st.top().first, l = st.top().second;
            int mid = (s + l)/2;
            st.pop();
            if(mid+1 > l)    ordered[mid]->right = NULL;
            else if(s > mid-1)  ordered[mid]->left = NULL;
            else{
                st.push(mid+1, l);
                st.push(mid,mid);
                st.push(s, mid-1);
            }
        }
        */
        if(start > last)    return NULL;
        int mid = (start + last)/2;
        ordered[mid]->left = arrToTree(start, mid-1);
        ordered[mid]->right = arrToTree(mid+1, last);
        return ordered[mid];
    }
};