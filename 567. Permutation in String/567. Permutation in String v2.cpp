class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26,0);
        const int ss1 = s1.size(), ss2 = s2.size();
        if(ss1 > ss2)   return false;
        for(int i = 0; i < ss1; ++i)
            if(s1[i] != s2[i])
                ++count[s1[i]-'a'], --count[s2[i]-'a'];
        
        int match = 0;
        for(auto& n: count)
            if(n == 0)  ++match;
        if(match == 26)  return true;

        for(int i = ss1; i < ss2; ++i){
            if(s2[i-ss1] == s2[i])  continue;

            if(count[s2[i-ss1]-'a']++ == 0) --match;
            else if(count[s2[i-ss1]-'a'] == 0) ++match;
            if(count[s2[i]-'a']-- == 0) --match;
            else if(count[s2[i]-'a'] == 0) ++match;
            
            if(match == 26) return true;
        }
        return false;
    }
};