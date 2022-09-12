TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    if(root->val == p->val || root->val == q->val) return root; // 👉 FIRST CONDITION...

    TreeNode* lca1 = lowestCommonAncestor(root->left, p, q);    // traverse on the left part of the tree
    TreeNode* lca2 = lowestCommonAncestor(root->right, p, q);   // traverse on the right part of the tree

    if(lca1 != NULL && lca2 != NULL) return root;   // 👉 SECOND CONDITION... (IF BOTH SUB-TREE CONTAINS 'p' & 'q' RESPECTIVELY)
        
    if(lca1 != NULL) return lca1;   // 👉 THIRD CONDITION...
    else return lca2;   // 👉 FOURTH CONDITION...
}