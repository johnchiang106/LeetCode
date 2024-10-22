class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = dividend < 0 == divisor < 0;
        long long absDividend = llabs(dividend);
        long long absDivisor = llabs(divisor);
        long long ans = 0;
        while(absDividend >= absDivisor){
            long long shift = 1, d = absDivisor;
            while(absDividend >= d){
                d <<= 1;
                shift <<= 1;
            }
            ans += shift>>1;
            absDividend -= d>>1;
        }
        if(ans > INT_MAX && positive)   return INT_MAX;
        return positive ? ans : -ans;
    }
};