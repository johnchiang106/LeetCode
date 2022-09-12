class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> total(n);
        unordered_map<int,int> m;
        
        m[0] = 1;
        total.front() = nums.front();
        m[nums.front()]++;
        int ans = (nums.front() == k) ? 1 : 0;
        
        for(int i = 1; i < n; ++i){
            total[i] = nums[i] + total[i-1];
            if(m.find(total[i]-k) != m.end())
                ans += m[total[i]-k];
            m[total[i]]++;
        }
        
        return ans;
    }
};