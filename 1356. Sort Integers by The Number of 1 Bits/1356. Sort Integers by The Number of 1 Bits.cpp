class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),mycompare);
        return arr;
    }
    static bool mycompare(int& a, int& b) {
        int c1 = __builtin_popcount(a), c2 = __builtin_popcount(b);
        if(c1 != c2)
            return c1 < c2;
        else
            return a < b;
    }
};