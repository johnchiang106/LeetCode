class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int col = grid[0].size();
        int ans = 0;
        vector<bool> landc(col,false);
        for(auto& row: grid){
            bool landr = false;
            for(int j =  0; j < col; ++j){
                if(row[j] == 1){
                    if(!landr){
                        ans += 2;
                        landr = true;
                    }
                    if(!landc[j]){
                        ans += 2;
                        landc[j] = true;
                    }
                }
                else{
                    if(landr)   landr = false;
                    if(landc[j])  landc[j] = false;
                }
            }
        }
        return ans;
    }
};