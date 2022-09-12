class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0;
        char pre = 'a';
        for(char ch: word){
            char dif = abs(ch - pre);
            if(dif <= 13)   ans += dif;
            else    ans += (26 - dif);
            pre = ch;
        }
        return ans + word.size();
    }
};