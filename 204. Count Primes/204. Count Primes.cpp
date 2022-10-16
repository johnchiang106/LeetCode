class Solution {
public:
    int countPrimes(int n) {
        if(n < 3)  return 0;
        vector<bool> primes(n-2,true);
        int ans = 0;
        for(int i = 2; i < n; ++i){
            if(!primes[i-2])  continue;
            ++ans;
            if(i <= n/i)
                for(int j = i*i; j < n; j+=i)
                    primes[j-2] = false;
        }
        return ans;
    }
};