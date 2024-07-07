/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "";
        
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        while(!q.empty()){
            cur = q.front();
            ans += to_string(cur->val);
            if(!cur->left && !cur->right){
                ans.push_back('a');
            }
            else if(!cur->left && cur->right){
                ans.push_back('b');
                q.push(cur->right);
            }
            else if(cur->left && !cur->right){
                ans.push_back('c');
                q.push(cur->left);
            }
            else{
                ans.push_back('d');
                q.push(cur->left);
                q.push(cur->right);
            }
            q.pop();
        }
        cout<<ans<<endl;
        return ans;
    }
    // 1d2a3d4a5a

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())    return new TreeNode();
        string temp = "";
        queue<pair<TreeNode*,char>> q;
        bool r = false;
        TreeNode* root;
        
        for(auto it = data.begin(); it != data.end(); ++it){
            if(*it > '9'){
                TreeNode* newN = new TreeNode(stoi(temp));
                if(!r){
                    root = newN;
                    r = true;
                }
                temp.clear();
                if(!q.empty()){
                    if(q.front().second == 'b'){
                        q.front().first->right = newN;
                        q.pop();
                    }
                    else if(q.front().second == 'c'){
                        q.front().first->left = newN;
                        q.pop();
                    }
                    else if(q.front().second == 'd'){
                        q.front().first->left = newN;
                        q.front().second = 'b';
                    }
                }
                if(*it != 'a')  q.push({newN,*it});
            }
            else{
                temp.push_back(*it);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));