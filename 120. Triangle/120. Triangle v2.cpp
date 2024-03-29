class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int s = triangle.size();
        for(int i = 1; i < s; ++i){
            for(int j = 0; j <= i; ++j){
                if(j == 0)
                    triangle[i][j] += triangle[i-1][0];
                else if(j == i)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};