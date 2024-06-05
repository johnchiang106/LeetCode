class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxLength = 0;
        int n = nums.size();
        int j = 0;
        deque<int> dqmin, dqmax;

        for (int i = 0; i < n; ++i)
        {
            while (!dqmax.empty() && dqmax.back() < nums[i]) dqmax.pop_back();

            while (!dqmin.empty() && dqmin.back() > nums[i]) dqmin.pop_back();

            dqmin.push_back(nums[i]);
            dqmax.push_back(nums[i]);

            if (dqmax.front() - dqmin.front() <= limit) maxLength = max(maxLength, i - j + 1);
            else 
            {
                if (nums[j] == dqmax.front()) dqmax.pop_front();
                else if (nums[j] == dqmin.front()) dqmin.pop_front();
                ++j;
            }
        }

        return maxLength;
    }
};