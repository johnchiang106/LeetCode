class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<string>::iterator iter, s1 = strs.begin(), s2 = strs.begin() + 1;
        string ans = "";
        if(strs.empty()) return ans;
        if(strs.size() == 1)    return strs[0];
        //see the prefix of the 2 strings
        string::iterator it1 = (*s1).begin(), it2 = (*s2).begin();
        for(; it1 != (*s1).end(); ++it1, ++it2){
            if(*it1 != *it2)    break;
            else    ans.push_back(*it1);
        }
        if(ans.empty()) return ans;
        if(strs.size() == 2)    return ans;
        //see if all the strings have those prefix
        it2 = ans.begin();
        for(iter = strs.begin() + 2; iter != strs.end(); ++iter, it2 = ans.begin()){
            if((*iter).empty()){
                ans = "";
                return ans;
            }
            for(it1 = (*iter).begin(); it1 != (*iter).end() || it2 != ans.end(); ++it1, ++it2){
			if(*it1 != *it2 || it1 == (*iter).end() || it2 == ans.end()){
                    ans = ans.substr(0, it1 - (*iter).begin());
                    if(ans.empty()) return ans;
                    break;
                }
            }
        }
        return ans;
    }
};