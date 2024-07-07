class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> rightSum;
        int leftSum = nums[0];
        
        rightSum.push_back(nums.back());
        for(int i = nums.size() - 2; i > 0; i--){
            rightSum.push_back(nums[i] + rightSum[nums.size()-2-i]);
        }
        if(rightSum.back() == 0)    return 0;
        
        for(int i = 1; i < rightSum.size(); i++){
            if(leftSum == rightSum[rightSum.size()-1-i])    return i;
            leftSum += nums[i];
        }
        if(leftSum == 0)    return nums.size() - 1;
        
        return -1;
    }
};