class Solution {
public:
    int characterReplacement(string s, int k) {
        int ss = s.size(), ans = k, maxN = 0, start = 0;
        vector<int> count(26,0);
        for(int i = 0; i < ss; ++i){
            maxN = max(maxN,++count[s[i]-'A']);
            if(i-start+1 - maxN > k){
                --count[s[start]-'A'];
                ++start;
            }
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};