class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int low = 0, high = a.size()-1, mid;
        vector<int> ans(2, -1);
        //first occurrence
        while(low <= high){
            mid = (low + high) / 2;
            if(a[mid] < target)    low = mid+1;
            else if(a[mid] > target)    high = mid-1;
            else if(mid == low || a[mid] != a[mid-1]){
                ans[0] = mid;
                break;
            }
            else    high = mid-1;
        }

        //last occurrence
        low = 0, high = a.size()-1;
        while(low <= high){
            mid = low + (high-low)/2;
            if(a[mid] < target)    low = mid+1;
            else if(a[mid] > target)    high = mid-1;
            else if(mid == high || a[mid] != a[mid+1]){
                ans[1] = mid;
                break;
            }
            else    low = mid+1;
        }
        return ans; 
    }
};