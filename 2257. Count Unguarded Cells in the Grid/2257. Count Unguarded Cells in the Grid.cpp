class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ans = m*n;
        vector<vector<char>> grid(m, vector<char>(n,0));
        for(auto& wall: walls){
            grid[wall[0]][wall[1]] = 2;
        }
        ans -= walls.size();
        for(auto& guard: guards){
            for(int row = guard[0]; row < m; ++row){
                if(grid[row][guard[1]] == 0){
                    grid[row][guard[1]] = 3;
                    --ans;
                    continue;
                }
                if(grid[row][guard[1]] < 4)    break;
            }
            for(int row = guard[0]-1; row >= 0; --row){
                if(grid[row][guard[1]] == 0){
                    grid[row][guard[1]] = 3;
                    --ans;
                    continue;
                }
                if(grid[row][guard[1]] < 4)    break;
            }
            for(int col = guard[1]+1; col < n; ++col){
                if(grid[guard[0]][col] == 0){
                    grid[guard[0]][col] = 4;
                    --ans;
                    continue;
                }
                if(grid[guard[0]][col] < 3
                 || grid[guard[0]][col] == 4)    break;
            }
            for(int col = guard[1]-1; col >= 0; --col){
                if(grid[guard[0]][col] == 0){
                    grid[guard[0]][col] = 4;
                    --ans;
                    continue;
                }
                if(grid[guard[0]][col] < 3
                 || grid[guard[0]][col] == 4)    break;
            }
        }
        return ans;
    }
};