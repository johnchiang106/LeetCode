class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int n = nums.size();
        if(n < 4) return {};
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        // vector<pair<int,int>> dup;
        // int i = 0;
        // for(int j = 1; j < n; ++j){
        //     if(num[j-1] != num[j]){
        //         dup.push_back({i,j-1});
        //         i = j;
        //     }
        // }
        // dup.push_back({i,n-1});
        
        for(int a = 0; a+3 < n;){
            for(int b = a+1; b+2 < n;){
                long long t = target;
                t -= nums[a]+nums[b];
                int c = b+1, d = n-1;
                while(c < d){
                    if(nums[c]+nums[d] == t){
                        ans.push_back({nums[a],nums[b],nums[c],nums[d]});
                        do  ++c;
                        while(c < d && nums[c-1] == nums[c]);
                        do  --d;
                        while(c < d && nums[d+1] == nums[d]);
                    }
                    else if(nums[c]+nums[d] < t){
                        do  ++c;
                        while(c < d && nums[c-1] == nums[c]);
                    }
                    else{
                        do  --d;
                        while(c < d && nums[d+1] == nums[d]);
                    }
                }
                while(b+2 < n && nums[b] == nums[++b]);
            }
            while(a+3 < n && nums[a] == nums[++a]);
        }
        return ans;
    }
};