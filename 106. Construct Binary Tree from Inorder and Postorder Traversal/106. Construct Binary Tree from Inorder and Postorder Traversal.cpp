class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIt = postorder.rbegin();
        inIndexOf.clear();

        int n = postorder.size();
        for (int i = 0 ; i < n ; ++i)
            inIndexOf[inorder[i]] = i;
        
        return build(inorder, 0, n - 1);
    }
private:
    vector<int>::reverse_iterator postIt; 
    unordered_map<int,int> inIndexOf;
    TreeNode* build(vector<int>& inorder, int in1, int in2) {
        TreeNode* root = new TreeNode(*postIt);
        
        int split = inIndexOf[*postIt];
        ++postIt;
        
        if (split + 1 <= in2)
            root->right = build(inorder, split + 1, in2);
        if (in1 <= split - 1)
            root->left = build(inorder, in1, split - 1);
        
        return root;
    }
};