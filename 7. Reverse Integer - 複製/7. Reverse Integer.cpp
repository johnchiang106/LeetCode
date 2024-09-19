class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)    return 0;
        bool positive = x >= 0;
        if(!positive)   x *= -1;
        int ans = 0;
        while(x > 0){
            if(ans > INT_MAX / 10)  return 0;
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        if(!positive)   ans *= -1;
        return ans;
    }
};