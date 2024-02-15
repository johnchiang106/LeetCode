class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        stringstream ss(s);
        string str;
        
        for(auto& c: pattern){
            getline(ss, str, ' ');
            if(mp.find(c) == mp.end()){
                mp[c] = str;
            }
            else if(mp[c] != str){
                return false;
            }
            if(mp2.find(str) == mp2.end()){
                mp2[str] = c;
            }
            else if(mp2[str] != c){
                return false;
            }
        }
        return !getline(ss, str, ' ');
    }
};