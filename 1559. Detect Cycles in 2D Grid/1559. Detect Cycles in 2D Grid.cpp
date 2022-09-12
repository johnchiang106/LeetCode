class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(!vis[i][j] && dfs(i, j, -1, grid, vis))
                    return true;
        return false;
    }
    bool dfs(int i, int j, char last, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        // cout<<"("<<i<<","<<j<<") ";
        if(j < n-1 && last != 2 && grid[i][j] == grid[i][j+1]){
            if(vis[i][j+1])    return true;
            vis[i][j+1] = true;
            if(dfs(i, j+1, 0, grid, vis)) return true;
        }
        if(i < m-1 && last != 3 && grid[i][j] == grid[i+1][j]){
            if(vis[i+1][j])    return true;
            vis[i+1][j] = true;
            if(dfs(i+1, j, 1, grid, vis)) return true;
        }
        if(j > 0 && last != 0 && grid[i][j] == grid[i][j-1]){
            if(vis[i][j-1])    return true;
            vis[i][j-1] = true;
            if(dfs(i, j-1, 2, grid, vis)) return true;
        }
        if(i > 0 && last != 1 && grid[i][j] == grid[i-1][j]){
            if(vis[i-1][j])    return true;
            vis[i-1][j] = true;
            if(dfs(i-1, j, 3, grid, vis)) return true;
        }
        return false;
    }
private:
    int m, n;
};