class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        ans.reserve(m*n);
        int limit[4] = {0, n, m, -1};
        char dir = 1, i = 0, j = 0;
        while(!finished(limit, dir, i, j)){
            if(dir == 0){
                while(i > limit[0])
                    ans.push_back(matrix[i--][j]);
                ++i, ++j, ++limit[0];
            }
            else if(dir == 1){
                while(j < limit[1])
                    ans.push_back(matrix[i][j++]);
                ++i, --j, --limit[1];
            }
            else if(dir == 2){
                while(i < limit[2])
                    ans.push_back(matrix[i++][j]);
                --i, --j, --limit[2];
            }
            else{
                while(j > limit[3])
                    ans.push_back(matrix[i][j--]);
                --i, ++j, ++limit[3];
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
    bool finished(int* lim, char& dir, char& i, char& j){
        if(dir == 0)    return i <= lim[0];
        if(dir == 1)    return j >= lim[1];
        if(dir == 2)    return i >= lim[2];
        return j <= lim[3];
    }
};