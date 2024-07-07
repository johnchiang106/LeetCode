class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i = 1, j = 1; i <= n; ++i){
            if(i == j){
                ans[i] = 1;
                j <<= 1;
            }
            else
                ans[i] = ans[i^ (j>>1) ] + 1;
        }
        return ans;
    }
};