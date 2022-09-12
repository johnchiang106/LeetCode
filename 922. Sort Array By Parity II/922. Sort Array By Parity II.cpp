class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for(int i = 0, j = 1; i < nums.size(); i+=2){
            if(nums[i]%2 != 0){
                for(; j < nums.size(); j += 2){
                    if(nums[j]%2 == 0){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};