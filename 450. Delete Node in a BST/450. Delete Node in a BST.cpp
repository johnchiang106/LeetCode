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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *keyNode = root, *keyNode0 = NULL;
        while(keyNode && keyNode->val != key){  // find key node and its parent
            keyNode0 = keyNode;
            keyNode = (keyNode->val > key) ? keyNode->left : keyNode->right;
        }
        if(!keyNode)   return root; // return root if not found key

        TreeNode** keyNodeEdge;
        if(keyNode0)
            keyNodeEdge = (keyNode0->val > key) ? &keyNode0->left : &keyNode0->right;
        if(!keyNode->left && !keyNode->right){  // the key node has no child
            delete keyNode;
            if(!keyNode0) return NULL;  // if there's only one node with key
            *keyNodeEdge = NULL;
            return root;
        }

        TreeNode *supp, *supp0 = keyNode;
        // find a node and its parent to supplement the key node
        if(keyNode->right){
            supp = keyNode->right;
            while(supp->left){
                supp0 = supp;
                supp = supp->left;
            }
        }
        else{
            supp = keyNode->left;
            while(supp->right){
                supp0 = supp;
                supp = supp->right;
            }
        }
        
        // concat the supp's parent and the supp's child
        // if the supp is key node's child, no need to concat
        if(supp0->left == supp && keyNode->left != supp)
            supp0->left = (supp->right) ? supp->right : NULL;
        if(supp0->right == supp && keyNode->right != supp)
            supp0->right = (supp->left) ? supp->left : NULL;
        
        // replace the key node with the supp node
        if(keyNode->left != supp)
            supp->left = keyNode->left;
        if(keyNode->right != supp)
            supp->right = keyNode->right;
        delete keyNode;
        if(!keyNode0) return supp;
        
        *keyNodeEdge = supp;
        return root;
    }
};