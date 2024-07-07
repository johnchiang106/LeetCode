class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1, s = nums.size();
        priority_queue<int> maxPq;
        priority_queue<int, vector<int>, greater<int>> minPq;
        unordered_map<int, int> mp;

        int i = 0, j = 0;
        minPq.push(nums[0]);
        maxPq.push(nums[0]);
        ++mp[0];
        while(j < s){
            while(maxPq.top() - minPq.top() <= limit && j != s){
                int& n = nums[j];
                if(mp[n] == 0){
                    minPq.push(n);
                    maxPq.push(n);
                }
                ++j;
                ++mp[n];
            }
            ans = max(ans, j - i - 1);
            while(maxPq.top() - minPq.top() > limit){
                int& n = nums[i];
                --mp[n];
                while(mp[maxPq.top()] == 0){
                    maxPq.pop();
                }
                while(mp[minPq.top()] == 0){
                    minPq.pop();
                }
                ++i;
            }
        }
        ans = max(ans, j - i);

        return ans;
    }
};