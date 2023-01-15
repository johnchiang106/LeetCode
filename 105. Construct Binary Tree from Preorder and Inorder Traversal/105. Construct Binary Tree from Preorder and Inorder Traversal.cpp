class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIt = preorder.begin();
        inIndexOf.clear();

        int n = preorder.size();
        for (int i = 0 ; i < n ; i++)
            inIndexOf[inorder[i]] = i;
        
        return build(inorder, 0, n - 1);
    }
private:
    vector<int>::iterator preIt;
    unordered_map<int,int> inIndexOf;
    TreeNode* build(vector<int>& inorder, int in1, int in2) {
        TreeNode* root = new TreeNode(*preIt);
        
        int split = inIndexOf[*preIt];
        ++preIt;
        
        if (in1 <= split - 1)
            root->left = build(inorder, in1, split - 1);
        if (split + 1 <= in2)
            root->right = build(inorder, split + 1, in2);
        
        return root;
    }
};