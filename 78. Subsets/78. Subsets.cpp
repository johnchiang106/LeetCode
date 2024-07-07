class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int s = nums.size(), end = pow(2,s);
        vector<vector<int>> ans;
        ans.reserve(end);
        for(int count = 0; count < end; ++count){
            vector<int> v;
            int bit = count;
            for(auto& n: nums){
                if(bit & 1)
                    v.push_back(n);
                bit >>= 1;
                if(bit == 0)
                    break;
            }
            ans.push_back(v);
        }
        return ans;
    }
};