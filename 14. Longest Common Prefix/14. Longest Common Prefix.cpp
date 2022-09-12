class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<string>::iterator iter, shortest1, shortest2;
        string ans = "";
        if(strs.empty()) return ans;
        if(strs.size() == 1)    return strs[0];
        //find the shortest string and the second shortest string
        if(strs[0].size()<strs[1].size()){
            shortest1 = strs.begin();
            shortest2 = strs.begin() + 1;
        }else{
            shortest1 = strs.begin() + 1;
            shortest2 = strs.begin();
        }
        if(strs.size() > 2){
            for(iter = strs.begin() + 2; iter != strs.end(); ++iter){
                if((*iter).size() < (*shortest1).size()){
                    shortest2 = shortest1;
                    shortest1 = iter;
                }
            }
        }
        //see the prefix of the 2 shortest strings
        string::iterator it1 = (*shortest1).begin(), it2 = (*shortest2).begin();
        for(; it1 != (*shortest1).end(); ++it1, ++it2){
            if(*it1 != *it2)    break;
            else    ans.push_back(*it1);
        }
        if(ans.empty()) return ans;
        //see if all the strings have those prefix
        it2 = ans.begin();
        for(iter = strs.begin(); iter != strs.end(); ++iter, it2 = ans.begin()){
            if(iter == shortest1 || iter == shortest2)	continue;
            for(it1 = (*iter).begin(); it1 != (*iter).end(); ++it1, ++it2){
                if(*it1 != *it2){
                    ans = ans.substr(0, it1 - (*iter).begin());
                    if(ans.empty()) return ans;
                    break;
                }
            }
        }
        return ans;
    }
};