class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length, n = mat[0].length, mn = arr.length;
        int[][] mp = new int[mn][2];
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                mp[mat[i][j]-1] = new int[]{i,j};
            }
        }
        int[] countRow = new int[m], countCol = new int[n];
        Arrays.fill(countRow,0);
        Arrays.fill(countCol,0);
        for(int i = 0; i < mn; ++i){
            int r = mp[arr[i]-1][0], c = mp[arr[i]-1][1];
            if(++countRow[r] >= n || ++countCol[c] >= m)  return i;
        }
        return arr.length;
    }
}