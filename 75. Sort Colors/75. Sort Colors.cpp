class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return;
    }
    void quickSort(vector<int>& nums, int start, int end){
        if(start >= end)    return;
        
        int i = start - 1;
        for (int j = start; j < end; ++j)
            if (nums[j] < nums[end])
                swap(nums[++i], nums[j]);
        swap(nums[++i], nums[end]);

        quickSort(nums, start, i - 1);
        quickSort(nums, i + 1, end);
        
        return;
    }
};