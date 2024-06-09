class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])  return 0;
        vector<int> paths(n,0);
        paths[0] = 1;
        for(int i = 0; i < m; ++i){
            if(obstacleGrid[i][0])  paths[0] = 0;
            for(int j = 1; j < n; ++j)
                paths[j] += obstacleGrid[i][j] ? -paths[j] : paths[j-1];
        }
        return paths[n-1];
    }
};