class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1)  return x;
        double ans = 1, n2 = x;
        bool neg = false, least = false;
        if(n < 0){
            if(n == INT_MIN){
                ++n;
                least = true;
            }
            n *= -1;
            neg = true;
        }
        while(n >= 1){
            if(n & 1)   ans *= n2;
            n >>= 1;
            n2 *= n2;
        }
        if(neg){
            ans = 1/ans;
            if(least)   ans /= x;
        }
        return ans;
    }
};