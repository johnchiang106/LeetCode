class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = dominoes;
        const int n = dominoes.size();
        char curr = '.';
        int falled = -1;
        for(int i = 0; i < n; ++i){
            if(curr == '.'){
                if(dominoes[i] == 'L'){
                    for(int j = i-1; j > falled; --j)
                        ans[j] = 'L';
                    falled = i;
                }
                else if(dominoes[i] == 'R'){
                    falled = i;
                    curr = 'R';
                }
            }
            else if(curr == 'R'){
                if(dominoes[i] == 'L'){
                    for(int j = falled+1, k = i-1; j < k; ++j, --k){
                        ans[j] = 'R';
                        ans[k] = 'L';
                    }
                    falled = i;
                    curr = '.';
                }
                else if(dominoes[i] == 'R'){
                    for(int j = i-1; j > falled; --j)
                        ans[j] = 'R';
                    falled = i;
                }
            }
        }
        if(curr == 'R' && falled != n-1){
            for(int i = n-1; i > falled; --i)
                ans[i] = 'R';
        }
        return ans;
    }
};