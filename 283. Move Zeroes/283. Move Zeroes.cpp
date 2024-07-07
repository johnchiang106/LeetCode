class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=0){
        //         swap(nums[i],nums[count++]);
        //     }
        // }
        for(auto i = nums.begin(), j = nums.begin(); i != nums.end(); ++i){
            if(*i != 0){
                iter_swap(i,j++);
            }
        }
    }
};