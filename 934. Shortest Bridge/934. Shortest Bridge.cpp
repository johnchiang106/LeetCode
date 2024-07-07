class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>> q;
        bool found = false;
        for(int i = 0; i < n && !found; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    dfs(grid, q, i, j);
                    found = true;
                    break;
                }
            }
        }
        vector<int> dir = {0, -1, 1, 1, -1};
        // 0 -1 0 1
        // -1 0 1 0
        int ans = 0;
        while(!q.empty()){
            for(int s = q.size(); s > 0; --s){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k < 4; ++k){
                    i += dir[k];
                    j += dir[k+1];
                    if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 2)
                        continue;
                    if(grid[i][j] == 1)
                        return ans;
                    if(grid[i][j] == 0){
                        q.push({i, j});
                        grid[i][j] = 2;
                    }
                }
            }
            ++ans;
        }
        return ans;
    }
private:
    int n;
    void dfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int i, int j){
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1)
            return;
        ++grid[i][j];
        q.push({i, j});
        dfs(grid, q, i, j-1);
        dfs(grid, q, i, j+1);
        dfs(grid, q, i-1, j);
        dfs(grid, q, i+1, j);
        return;
    }
};