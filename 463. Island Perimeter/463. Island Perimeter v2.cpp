class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int row = grid.size();
        const int col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; ++i){
            for(int j =  0; j < col; ++j){
                if(grid[i][j] == 1){
                    if(j == 0 || grid[i][j-1] == 0) ans += 2;
                    if(i == 0 || grid[i-1][j] == 0) ans += 2;
                }
            }
        }
        return ans;
    }
};