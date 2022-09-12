class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();
        int r1 = 0, r2 = 1, minR = 0;
        vector<int> ac(n,0);
        while(k >= 1){
            minR = r1;
            for(int i = r1+1; i <= r2; ++i){
                if(i == n) break;
                if(ac[minR] < n && ac[i] < n && 
                   matrix[minR][ac[minR]] > matrix[i][ac[i]])
                    minR = i;
            }
            if(minR == r2 && r2 != n-1)   ++r2;
            if(ac[minR] == n-1) ++r1;
            ++ac[minR], --k;
        }
        return matrix[minR][ac[minR]-1];
    }
};