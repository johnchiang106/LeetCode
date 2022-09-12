class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> father;
        father.resize(edges.size()+1);
        iota(father.begin(),father.end(),0);
        int ch = 0; //child with 2 father
        for(auto& edge: edges){
            if(father[edge[1]] != edge[1]){
                ch = edge[1];
                father[0] = edge[0];
            }
            else    father[edge[1]] = edge[0];
        }
        
        if(ch != 0){
            int temp = father[ch];
            father[ch] = ch;
            if(find(temp,father) == ch)  return {temp,ch};
            else    return {father[0],ch};
        }
        
        for(auto it = edges.rbegin(); it != edges.rend(); ++it){
            // bool pass = true;
            vector<int> f2(father.begin(),father.end());
            
            ch = (*it)[1];
            f2[ch] = ch;
            for(int i = 1; i < f2.size(); ++i){
                if(find(f2[i], f2) == ch){
                    if(f2[i] != ch) f2[i] = ch;
                }
                else{
                    goto c;
                    // pass = false;
                    // break;
                }
            }
            // if(pass)    return *it;
            return *it;
            c:;
        }
        
        return {};
        
    }
private:
    int find(int child, vector<int>& f) {
        if(child == f[child])  return child;
        int temp = f[child];
        while(temp != f[temp]){
            if(temp == child)
                return 0;
            temp = f[temp];
        }
        return temp;
    }
};