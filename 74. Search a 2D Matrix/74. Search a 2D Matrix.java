class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length, l = 0, r = m*n-1, mid;
        while(l <= r){
            mid = l + (r - l)/2;
            if(matrix[mid/n][mid%n] < target){
                l = mid+1;
            }
            else if(matrix[mid/n][mid%n] > target){
                r = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
}