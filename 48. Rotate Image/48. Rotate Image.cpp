class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; ++i){
            int end = n-1-i;
            for(int j = 0; j < end-i; ++j){
                int temp = matrix[i][i+j];
                matrix[i][i+j] = matrix[end-j][i];
                matrix[end-j][i] = matrix[end][end-j];
                matrix[end][end-j] = matrix[i+j][end];
                matrix[i+j][end] = temp;
            }
        }
    }
};