class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, ans = 0;
        for(char& c: s){
            if(c == '(')    open++;
            else if(open == 0)   ans++;
            else    open--;
        }
        ans += open;
        return ans;
    }
};