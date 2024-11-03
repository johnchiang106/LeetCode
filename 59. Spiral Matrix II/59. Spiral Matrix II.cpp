class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        ans.resize(n, vector<int>(n,0));
        int limit[4] = {0, n, n, -1};
        char dir = 1, i = 0, j = 0;
        int num = 1;
        while(!finished(limit, dir, i, j)){
            if(dir == 0){
                while(i > limit[0])
                    ans[i--][j] = num++;
                ++i, ++j, ++limit[0];
            }
            else if(dir == 1){
                while(j < limit[1])
                    ans[i][j++] = num++;
                ++i, --j, --limit[1];
            }
            else if(dir == 2){
                while(i < limit[2])
                    ans[i++][j] = num++;
                --i, --j, --limit[2];
            }
            else{
                while(j > limit[3])
                    ans[i][j--] = num++;
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