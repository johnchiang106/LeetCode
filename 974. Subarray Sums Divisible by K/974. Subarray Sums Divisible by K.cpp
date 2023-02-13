class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> total(n);
        unordered_map<int,int> m;
        
        m[0] = 1;
        total.front() = nums.front()%k;
        if(total.front() < 0)    total.front() += k;
        m[total.front()]++;
        int ans = (nums.front()%k == 0 ) ? 1 : 0;
        
        for(int i = 1; i < n; ++i){
            total[i] = nums[i] + total[i-1];
            total[i] %= k;
            if(total[i] < 0)    total[i] += k;
            if(m.find(total[i]) != m.end())
                ans += m[total[i]];
            m[total[i]]++;
        }
        
        return ans;
    }
};