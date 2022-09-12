class Solution {
public:
    int balancedStringSplit(string s) {
        int num = 0, ans = 0;
        for(char& c: s){
            if(num == 0)    ++ans;
            if(c == 'R')    ++num;
            else    --num;
        }
        return ans;
    }
};