class Solution {
public:
    int longestSubstring(string& s, int k) {
        unordered_map<char,int> mp;
        vector<int> invalid(1,-1);
        int n = s.size();
        if(k > n) return 0;
        for(auto& c: s){
            ++mp[c];
        }
        for(int i = 0; i < n; ++i){
            if(mp[s[i]] < k)
                invalid.push_back(i);
        }
        invalid.push_back(n);
        int in = invalid.size()-1, ans = 0;
        for(int i = 0; i < in; ++i){
            int&& len = invalid[i+1]-invalid[i]-1;
            if(len < k || len <= ans)
                continue;
            mp.clear();
            for(int j = invalid[i]+1; j < invalid[i+1]; ++j){
                ++mp[s[j]];
            }
            bool success = true;
            for(auto& p: mp){
                if(p.second < k){
                    success = false;
                    break;
                }
            }
            if(success) ans = len;
        }
        return ans;
    }
};