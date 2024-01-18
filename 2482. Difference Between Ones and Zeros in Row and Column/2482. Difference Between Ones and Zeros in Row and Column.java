class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] diffRow = new int[m], diffCol = new int[n];
        Arrays.fill(diffRow,n);
        Arrays.fill(diffCol,m);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0){
                    diffRow[i] -= 2;
                    diffCol[j] -= 2;
                }
            }
        }
        int[][] ans = new int[m][n];
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                ans[i][j] = diffRow[i] + diffCol[j];
            }
        }
        return ans;
    }
}