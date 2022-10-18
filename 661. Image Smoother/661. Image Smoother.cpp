class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int sum = 0, count = 0;
                for(int a = -1; a < 2; ++a){
                    for(int b = -1; b < 2; ++b){
                        if(i+a >= 0 && i+a < m && j+b >= 0 && j+b < n){
                            sum += img[i+a][j+b];
                            ++count;
                        }
                    }
                }
                ans[i][j] = sum/count;
            }
        }
        return ans;
    }
};