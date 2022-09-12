class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)	return nums.size();
        auto it = nums.begin() + 1, it2 = it;
        while(it != nums.end()){
            if(*it != *(it-1))  *it2++ = *it;
            ++it;
        }
        return it2 - nums.begin();
    }
};