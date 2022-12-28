class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26,0), c2(26,0);
        const int ss1 = s1.size(), ss2 = s2.size();
        if(ss1 > ss2)   return false;
        for(const auto& ch: s1)
            ++count[ch-'a'];
        for(int i = 0, j = 0; j < ss2; ++j){
            char&& curr = s2[j]-'a';
            if(count[curr] == 0){
                c2 = vector<int>(26,0);
                i = j+1;
                continue;
            }
            ++c2[curr];
            while(c2[curr] > count[curr]){
                --c2[s2[i]-'a'], ++i;
            }
            if(j-i+1 == ss1) return true;
        }
        return false;
    }
};