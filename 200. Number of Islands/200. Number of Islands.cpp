class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islandIndex = 0;
        vector<int> row(n, -1);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '0'){
                    row[j] = -1;
                    continue;
                }
                if(i > 0 && grid[i-1][j] != '0'){
                    if(j > 0 && grid[i][j-1] != '0' && row[j-1] != row[j]){
                        join(row[j-1], row[j]);
                    }
                }
                else if(j > 0 && grid[i][j-1] != '0'){
                    row[j] = row[j-1];
                }
                else{
                    father.push_back(islandIndex);
                    row[j] = islandIndex++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < father.size(); ++i){
            if(i == father[i])
                ++ans;
        }
        father.clear();
        return ans;
    }
private:
    vector<int> father;
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }
};