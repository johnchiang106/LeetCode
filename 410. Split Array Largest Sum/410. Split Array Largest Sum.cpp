class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = nums[0], right = 0;
        for(int& n: nums){
            left = max(left, n);
            right += n;
        }
        if(k == 1)  return right;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(splitable(nums, k, mid))
                right = mid-1;
            else
                left = mid+1;
        }
        return right+1;
    }
    bool splitable(vector<int>& nums, int k, int& m) {
        int currSum = 0;
        for(int& n: nums){
            if(currSum + n > m){
                currSum = n;
                if(--k == 0)    return false;
            }
            else{
                currSum += n;
            }
        }
        return true;
    }
};