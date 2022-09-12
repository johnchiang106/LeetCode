class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        string ans = ""; 
        if(strs.empty()) return ans;
        if(strs.size() == 1)    return strs[0];
        sort(strs.begin(), strs.end());
        auto s1 = strs.begin(), s2 = strs.end()-1;
        auto it1 = (*s1).begin(), it2 = (*s2).begin();
        for(; it1 != (*s1).end(); ++it1, ++it2){
            if(*it1 != *it2)    break;
            else    ans.push_back(*it1);
        }
        return ans;
    }
};