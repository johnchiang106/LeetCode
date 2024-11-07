class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(m == 1){
            for(int j = 0; j < n; ++j){
                if(matrix[0][j] == 0){
                    fill(matrix[0].begin(), matrix[0].end(), 0);
                    return;
                }
            }
            return;
        }
        int store = -1;
        for(int i = 0; i < m && store == -1; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0)   break;
                if(j == n-1)    store = i;
            }
        }
        if(store == -1){
            for (auto& i : matrix)
                fill(i.begin(), i.end(), 0);
            return;
        }
        for(int i = 0; i < m; ++i){
            if(i == store)  continue;
            bool row = false;
            for(int j = 0; j < n; ++j){
                if(row){
                    if(matrix[i][j] == 0)
                        matrix[store][j] = 0;
                    matrix[i][j] = 0;
                    continue;
                }
                if(matrix[i][j] == 0){
                    row = true;
                    matrix[store][j] = 0;
                    fill(matrix[i].begin(), matrix[i].begin()+j, 0);
                }
            }
        }
        for(int j = 0; j < n; ++j)
            if(matrix[store][j] == 0)
                for(int k = 0; k < m; ++k)
                    matrix[k][j] = 0;
        return;
    }
};