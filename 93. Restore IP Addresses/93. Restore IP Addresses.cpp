class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        helper(0, s);
        return ans;
    }
    void helper(int i, string& s){
        if(nums.size() > 4)    return;
        if(i == s.size()){
            if(nums.size() != 4)    return;
            string str;
            for(int j = 0; j < 4; ++j){
                str += to_string(nums[j]);
                if(j != 3)  str.push_back('.');
            }
            ans.push_back(str);
            return;
        }
        if(s.size()-i > (4-nums.size())*3)  return;
        if(s[i] == '0'){
            nums.push_back(0);
            helper(i+1, s);
            nums.pop_back();
            return;
        }
        int n = 0;
        for(int j = i; j < i+3 && j < s.size(); ++j){
            n += s[j]-'0';
            if(n > 255) break;
            nums.push_back(n);
            helper(j+1, s);
            nums.pop_back();
            n *= 10;
        }
    }
    vector<int> nums;
    vector<string> ans;
};