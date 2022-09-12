class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n1 = p.size(), n2 = s.size();
        if(n1 > n2) return {};
        
        vector<int> ans;
        map<char,int> m;
        for(char& c: p)
            m[c]++;
        for(int i = 0; i < n1-1; ++i)
            m[s[i]]--;
        
        for(int i = n1-1; i < n2; ++i){
            if(--m[s[i]] == 0){
                for(auto& e: m)
                    if(e.second != 0)   goto next;
                ans.push_back(i-n1+1);
            }
            next:;
            ++m[s[i-n1+1]];
        }
        return ans;
    }
};