class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<int> maxV(n,0), maxH(n,0);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                maxV[i] = max(maxV[i], grid[i][j]);
                maxH[j] = max(maxH[j], grid[i][j]);
                if(grid[i][j] > 0){
                    ans += 2;
                    cout<<ans<<" ";
                }
                if(i > 0 && grid[i-1][j] > grid[i][j] && 
                   i < n-1 && grid[i+1][j] > grid[i][j]){
                    ans += 2*(min(grid[i-1][j],grid[i+1][j])-grid[i][j]);
                    cout<<ans<<" ";
                }
                if(j > 0 && grid[i][j-1] > grid[i][j] && 
                   j < n-1 && grid[i][j+1] > grid[i][j]){
                    ans += 2*(min(grid[i][j-1],grid[i][j+1])-grid[i][j]);
                    cout<<ans<<" ";
                }
            }
        }
        for(int i = 0; i < n; ++i){
            ans += 2*maxV[i]+2*maxH[i];
            cout<<endl<<maxV[i]<<" "<<maxH[i]<<" "<<ans<<endl;
        }
        return ans;
    }
};