class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        bool slash = false;
        int dot = 0;
        path.push_back('/');
        for(char& ch: path){
            if(ch == '/'){
                slash = true;
                if(dot == 2 && ans[ans.size()-3] == '/'){
                    ans.pop_back();
                    ans.pop_back();
                    if(ans.size() != 1){
                        ans.pop_back();
                        while(ans.back() != '/')    ans.pop_back();
                    }
                    ans.pop_back();
                }
                else if(dot == 1 && ans[ans.size()-2] == '/'){
                    ans.pop_back();
                    ans.pop_back();
                }
                dot = 0;
                continue;
            }
            if(slash){
                slash = false;
                ans.push_back('/');
            }
            if(ch == '.')  ++dot;
            ans.push_back(ch);
        }
        if(ans.empty()) return "/";
        return ans;
    }
};