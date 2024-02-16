class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        pair<int, bool> curr = {10001, true};
        int p = 0, ans = 0;
        for(auto& n: nums){
            if(n != curr.first){
                nums[p++] = n;
                curr = {n, true};
                ++ans;
            }
            else if(curr.second){
                nums[p++] = n;
                curr.second = false;
                ++ans;
            }
        }
        return ans;
    }
};