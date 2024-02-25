class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        if(m < n)   swap(m, n);
        store(m+n-2, m-1);
        while(--n > 1){
            int index = 0;
            while(stored[index] % n != 0)    ++index;
            stored[index] /= n;
        }
        return accumulate(stored.begin(), stored.end(), 1, multiplies<>{});;
    }
    void store(int num, int num2){
        int ans = num;
        while(--num > num2){
            if(INT_MAX / ans < num){
                stored.push_back(ans);
                ans = num;
            }
            else    ans *= num;
        }
        stored.push_back(ans);
        return;
    }
private:
    vector<int> stored;
};