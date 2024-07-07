class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1, ans = 0;
        sort(nums.begin(), nums.end());
        stored.reserve(j);
        stored.push_back(1);
        while(i <= j){
            while(i < j && nums[i] + nums[j] > target)
                --j;
            if(nums[i] * 2 > target)
                break;
            addNewMod(ans, j-i);
            ++i;
        }
        return ans;
    }
private:
    vector<int> stored;
    void addNewMod(int& ans, int val){
        long long temp = stored.back();
        if(val < stored.size())
            temp = stored[val];
        else{
            for(int i = stored.size(); i <= val; ++i){
                temp = (temp << 1) % 1000000007;
                stored.push_back((int)temp);
            }
        }
        ans = (temp + (long long)ans) % 1000000007;
    }
};