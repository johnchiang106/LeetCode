class Solution {
    public boolean checkValid(int[][] matrix) {
        int n = matrix.length;
        for(int i = 0; i < n; ++i){
            boolean[] arrRow = new boolean[n];
            boolean[] arrCol = new boolean[n];
            for(int j = 0; j < n; ++j){
                if(arrRow[matrix[i][j] - 1] || arrCol[matrix[j][i] - 1]) return false;
                arrRow[matrix[i][j] - 1] = true;
                arrCol[matrix[j][i] - 1] = true;
            }
        }
        return true;
    }
}