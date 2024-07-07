class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), oranges = 0;
        queue<pair<int,int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2){
                    rotten.emplace(i,j);
                }
                else if(grid[i][j] == 1){
                    ++oranges;
                }
            }
        }
        if(oranges == 0) return 0;
        int ans = -1;
        while(!rotten.empty()){
            ++ans;
            for(int k = rotten.size(); k > 0; --k){
                int i = rotten.front().first, j = rotten.front().second;
                rotten.pop();
                if(i > 0 && grid[i-1][j] == 1)  rot(grid, rotten, oranges, i-1, j);
                if(i < m-1 && grid[i+1][j] == 1)  rot(grid, rotten, oranges, i+1, j);
                if(j > 0 && grid[i][j-1] == 1)  rot(grid, rotten, oranges, i, j-1);
                if(j < n-1 && grid[i][j+1] == 1)  rot(grid, rotten, oranges, i, j+1);
            }
        }
        if(oranges > 0) return -1;
        return ans;
    }
private:
    void rot(vector<vector<int>>& grid, queue<pair<int,int>>& rotten, int& oranges, int i, int j){
        rotten.emplace(i,j);
        grid[i][j] = 2;
        --oranges;
    }
};