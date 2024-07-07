class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<set<string>> v;
        for(int i = 0; i < n; i++){
            set<string> s;
            v.push_back(s);
        }
        v[0].insert("()");
        
        for(int i = 1; i < n; i++){
            for(const string& str: v[i-1]){
                for(int j = 0; j <= 2*i; j++){
                    string temp = str;
                    temp.insert(j, "()");
                    v[i].insert(temp);
                }
            }
        }
        
        vector<string> ans;
        for(auto& s: v[n-1])    ans.push_back(s);
        return ans;
    }
};