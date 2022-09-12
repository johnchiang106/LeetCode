class Solution {
public:
    int climbStairs(int n) {
        int n1 = 1, n2 = 2;
        for(int i = 3; i <= n; ++i){
            if(i % 2 == 1)  n1 += n2;
            else            n2 += n1;
        }
        return (n % 2 == 1) ? n1 : n2;
    }
};