class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())	return 0;
        if(nums.size() == 1)	return 1;
        auto it = nums.begin() + 1;
        while(it != nums.end()){
            if(*it == *(it-1))  nums.erase(it);
            else    ++it;
        }
        return nums.size();
    }
};