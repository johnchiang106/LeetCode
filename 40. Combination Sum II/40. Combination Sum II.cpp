class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        count.resize(target+1);
        for(int& can: candidates){
            if(can > target)    continue;
            ++count[can];
        }
        vector<vector<int>> ans;
        int sum = 0;
        helper(1, sum, target, ans);
        return ans;
    }
    bool helper(int num, int& sum, const int& target, vector<vector<int>>& ans){
        if(sum > target)    return true;
        if(sum == target){
            ans.push_back(curr);
            return true;
        }
        if(count[num] == 0)
            return num == target ? true : helper(num+1, sum, target, ans);
        else{
            sum += num;
            curr.push_back(num);
            --count[num];
            bool exeed = helper(num, sum, target, ans);
            sum -= num;
            curr.pop_back();
            ++count[num];
            if(!exeed && num != target)
                helper(num+1, sum, target, ans);
        }
        return false;
    }
    vector<int> count, curr;
};