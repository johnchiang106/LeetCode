class Solution {
public:
    int jump(vector<int>& nums) {
        int s = nums.size()-1;
        if(s == 0)  return 0;
        int count = 1, i = 0;
        while(i + nums[i] < s){
            int next = i, val = 0;
            for(int j = nums[i] + i; j > i; --j){
                if(nums[j]-val > next-j){
                    val = nums[j];
                    next = j;
                }
            }
            i = next;
            ++count;
        }
        return count;
    }
};