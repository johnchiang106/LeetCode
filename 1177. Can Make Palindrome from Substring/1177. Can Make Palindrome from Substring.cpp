class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        const int n = queries.size();
        vector<bool> ans(n,true);
        vector<int> curr(26,0);
        vector<vector<int>> prev;
        prev.reserve(s.size()+1);
        
        prev.push_back(curr);
        for(auto& ch: s){
            ++curr[ch-'a'];
            prev.push_back(curr);
        }
        
        for(int i = 0; i < n; ++i){
            int left = queries[i][0], right = queries[i][1], k = queries[i][2]*2;
            if(right-left <= k)   continue;
            
            vector<int> charCount = prev[right+1];
            int odds = 0;
            for(int j = 0; j < 26; ++j){
                if(charCount[j] == 0)   continue;
                charCount[j] -= prev[left][j];
                if(charCount[j]%2 == 1){
                    if(odds++ > k){
                        ans[i] = false;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};