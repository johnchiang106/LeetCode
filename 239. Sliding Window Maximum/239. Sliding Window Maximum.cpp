class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        const int s = nums.size();
        ans.reserve(s-k+1);

        for(int j = 0; j < s; ++j){
            while(!dq.empty() && nums[dq.back()] < nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if(dq.front() <= j-k)
                dq.pop_front();
            if(j-k+1 >= 0)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};