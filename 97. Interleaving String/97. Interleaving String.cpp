class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int ss1 = s1.size(), ss2 = s2.size(), ss3 = s3.size();
        int i1 = 0, i2 = 0, i3 = 0;
        if(ss1 + ss2 != ss3)    return false;
        dp = vector<unordered_set<int>>(ss1+1, unordered_set<int>());
        return helper(s1, s2, s3, i1, i2, i3, ss1, ss2, ss3);
    }
private:
    vector<unordered_set<int>> dp;
    bool helper(string& s1, string& s2, string& s3, int i1, int i2, int i3, int& ss1, int& ss2, int& ss3){
        if(i3 == ss3)   return true;
        if(dp[i1].count(i2))    return false;
        if(i1 < ss1 && s1[i1] == s3[i3] && helper(s1, s2, s3, i1+1, i2, i3+1, ss1, ss2, ss3))
            return true;
        if(i2 < ss2 && s2[i2] == s3[i3] && helper(s1, s2, s3, i1, i2+1, i3+1, ss1, ss2, ss3))
            return true;
        dp[i1].insert(i2);
        return false;
    }
};