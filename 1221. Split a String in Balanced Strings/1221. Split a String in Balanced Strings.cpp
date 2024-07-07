class Solution {
public:
    int balancedStringSplit(string s) {
        bool r = true;
        int num = 0, ans = 0;
        for(char& c: s){
            if(num == 0){
                ++ans;
                r = (c == 'R');
                ++num;
            }
            else if(r == (c == 'R')) ++num;
            else    --num;
        }
        return ans;
    }
};