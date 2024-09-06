class Solution {
public:
    int numTrees(int n) {
        vector<int> unique(n+1,0);
        unique[0] = 1;
        unique[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = (i+1)/2; j < i; ++j){
                unique[i] += 2*(unique[j] * unique[i-1-j]);
            }
            if(i & 1){
                unique[i] += unique[i/2] * unique[i/2];
            }
        }
        return unique[n];
    }
};