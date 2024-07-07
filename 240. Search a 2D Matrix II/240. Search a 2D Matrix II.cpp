class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int right = matrix[0].size()-1;
        for(const auto& row: matrix){
            if(row[0] > target)
                return false;
            int l = 0, r = right, mid;
            while(l <= r){
                mid = l+(r-l)/2;
                if(row[mid] == target)
                    return true;
                if(row[mid] > target)
                    r = mid-1;
                else
                    l = mid+1;
            }
            right = max({l,r,mid})-1;
        }
        return false;
    }
};