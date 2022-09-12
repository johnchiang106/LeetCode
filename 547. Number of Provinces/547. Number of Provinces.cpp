class Solution {
private:
    vector<int> father;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        father = vector<int> (n,-1);
        
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                if(isConnected[i][j] == 1)
                    join(i,j);
        
        int ans = 0;
        for(auto& f: father)
            if(f == -1) ++ans;
        
        return ans;
    }
    
    int find(int u) {
        return father[u] == -1 ? u : father[u] = find(father[u]);
    }
    
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return;
        father[u] = v;
    }
};