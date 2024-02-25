class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        if(m < n)   swap(m, n);
        
        int num = m+n-2;
        long long ans = num;
        while(--num >= m){
            while(LLONG_MAX / ans < num){
                ans /= --n;
            }
            ans *= num;
        }
        
        while(--n > 1)
            ans /= n;
        return int(ans);
    }
};