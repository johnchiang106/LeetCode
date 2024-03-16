class Solution {
public:
    int myAtoi(string s) {
        int ans = 0, ss = s.size(), i = 0, large = INT_MAX / 10;
        bool sign = true;
        for(; i < ss; ++i){
            if(s[i] == '-' || s[i] == '+'){
                sign = s[i] == '+';
                ++i;
                break;
            }
            if(s[i] != ' ')    break;
        }
        for(; i < ss; ++i){
            if(!isdigit(s[i]))  break;
            int num = s[i] - '0';
            if(ans < large || (ans == large && num <= 7)){
                ans *= 10;
                ans += num;
            }
            else    return sign ? INT_MAX : INT_MIN;
        }
        return sign ? ans : -ans;
    }
};