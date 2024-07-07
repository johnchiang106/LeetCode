class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lChild, vector<int>& rChild) {
        vector<bool> parent(n, false);
        for(int i = 0; i < n; ++i){
            if (lChild[i] != -1){
                if(parent[lChild[i]])   return false;
                parent[lChild[i]] = true;
            }
            if (rChild[i] != -1){
                if(parent[rChild[i]])   return false;
                parent[rChild[i]] = true;
            }
        }
        
        int root = -1;
        for(int i = 0; i < n; ++i){
            if (parent[i])    continue;
            if (root != -1) return false;
            root = i;
        }
        
        return countNode(lChild,rChild,root) == n;
    }
    
    int countNode(vector<int> &left, vector<int> &right, int node){
        if(node == -1)  return 0;
        return 1 + countNode(left,right,left[node]) + countNode(left,right,right[node]);
    }
};