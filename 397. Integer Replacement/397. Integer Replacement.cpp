class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX)    return 32;
        int ans = 0;
        while(n > 1){
            if(n == 3)  return ans+2;
            if(n & 1){  //equivalent to n % 2 == 1
                if(n>>1 & 1)    ++n;  //equivalent to n % 4 == 3
                else    --n;
                ++ans;
            }
            n >>= 1;
            ++ans;
        }
        return ans;
    }
};