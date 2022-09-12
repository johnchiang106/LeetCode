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
        if(node == NULL)    return;
        orderElement(node->left);
        ordered.push_back(node);
        orderElement(node->right);
    }
    TreeNode* arrToTree(int first, int last){
        if(first > last)    return NULL;
        int mid = (first + last)/2;
        ordered[mid]->left = arrToTree(first, mid-1);
        ordered[mid]->right = arrToTree(mid+1, last);
        return ordered[mid];
    }
};