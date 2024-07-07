class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum=0;
        stack<pair<TreeNode*,int>> stck;
        stck.push({root,0});
        while(!stck.empty()){
            pair<TreeNode*,int> p=stck.top();
            stck.pop();
            TreeNode* cur_node=p.first;
            int cur_sum=p.second;
            if(cur_node!=NULL){
                cur_sum=cur_sum*10+cur_node->val;
                if(cur_node->left==NULL and cur_node->right==NULL){
                    totalSum+=cur_sum;
                }
                else{
                    if(cur_node->right){
                        stck.push({cur_node->right,cur_sum});
                    }
                    if(cur_node->left){
                        stck.push({cur_node->left,cur_sum});
                    }
                }
            }
        }
        return totalSum;
    }
};