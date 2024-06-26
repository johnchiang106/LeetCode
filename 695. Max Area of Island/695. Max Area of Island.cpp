class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j])
                    ans = max(ans, dfs(grid, i, j));
        return ans;
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        queue<pair<int,int>> q;
        q.emplace(i,j);
        int area = 0;
        while(!q.empty()){
            int i1 = q.front().first;
            int j1 = q.front().second;
            q.pop();
            if(!grid[i1][j1])   continue;
            ++area;
            grid[i1][j1] = 0;
            if(i1 > 0 && grid[i1-1][j1])    q.emplace(i1-1,j1);
            if(i1 < m-1 && grid[i1+1][j1])    q.emplace(i1+1,j1);
            if(j1 > 0 && grid[i1][j1-1])    q.emplace(i1,j1-1);
            if(j1 < n-1 && grid[i1][j1+1])    q.emplace(i1,j1+1);
        }
        return area;
    }
private:
    int m, n;
};