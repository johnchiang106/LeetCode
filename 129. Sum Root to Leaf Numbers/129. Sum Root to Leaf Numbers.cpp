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
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*,int>> s;
        int ans = 0, temp = 0, layer = 0;
        s.push({root,layer});
        
        while(!s.empty()){
            TreeNode* cur = s.top().first;
            layer = s.top().second;
            s.pop();
            temp = temp*10 + cur->val;
            
            if(cur->right || cur->left){
                layer++;
                if(cur->right)  s.push({cur->right,layer});
                if(cur->left)   s.push({cur->left,layer});
            }
            else{
                ans += temp;
                if(s.size() > 0)
                    temp /= pow(10,layer-s.top().second+1);
            }
        }
        return ans;
    }
};