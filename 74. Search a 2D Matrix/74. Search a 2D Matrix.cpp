class Solution {
public:
    #define m(n,num) matrix[(num)/(n)][(num)%(n)]
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size(), l = 0, r = n*matrix.size()-1, mid;
        while(l <= r){
            // mid = (l+r)/2;
            mid = l + (r-l)/2;
            if(m(n,mid) > target)
                r = mid-1;
            else if(m(n,mid) < target)
                l = mid+1;
            else
                return true;
        }
        return false;
    }
};