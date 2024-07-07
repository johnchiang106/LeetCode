class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator iter = nums.begin();
        if(nums.empty()) return 0;
        while(iter != nums.end()){
            if(*iter == val)    nums.erase(iter);
            else                ++iter;
        }
        return nums.size();
    }
};