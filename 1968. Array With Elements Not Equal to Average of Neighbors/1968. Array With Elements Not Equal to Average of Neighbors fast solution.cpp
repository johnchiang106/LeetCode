class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        auto i = nums.begin() + 1;
        while(i+1 != nums.end()){
            if((*(i-1) < *i && *i < *(i+1)) || (*(i-1) > *i && *i > *(i+1)))
                swap(*i, *(i+1));
            ++i;
        }
        return nums;
    }
};