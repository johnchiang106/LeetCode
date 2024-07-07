class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while(n > 0){
            if(n & 1){
                if(n & 2 && n & 12)
                    n += 1;
                ++ans;
            }
            n >>= 1;
        }
        return ans;
    }
};