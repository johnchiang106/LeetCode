class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        pair<int,bool> left = {0,false}, right = {nums[0],true};
        for(int i = 1; i < n; ++i){
            pair<int,bool> temp = right;
            if(left.first+nums[i] > right.first){
                right.first = left.first+nums[i];
                right.second = left.second;
            }
            else if(left.first+nums[i] < right.first){
                right.second = right.second;
            }
            else{
                right.second = false;
            }
            left = temp;
        }
        if(!left.second){
            right.first = max(left.first+nums.back(), right.first);
        }
        int ans = right.first;
        left.first = 0;
        right.first = 0;
        for(int i = 1; i <= n; ++i){
            int temp = right.first;
            right.first = max(left.first+nums[i], right.first);
            left.first = temp;
        }
        return max(ans, right.first);
    }
};