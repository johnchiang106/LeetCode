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
int dfs(TreeNode* curr, int& maxD){
    int pathL = -1, pathR = -1;
    if(curr->left){
        pathL = dfs(curr->left,maxD);
    }
    if(curr->right){
        pathR = dfs(curr->right,maxD);
    }
    maxD = max(maxD,pathL+pathR+2);
    // cout<<curr->val<<" "<<maxD<<endl;
    return max(pathL,pathR)+1;
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        dfs(root,maxD);
        return maxD;
    }
};