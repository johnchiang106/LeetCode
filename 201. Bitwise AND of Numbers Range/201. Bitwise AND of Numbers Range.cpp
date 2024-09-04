class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = INT_MAX;
        right ^= left;
        while (right > 0) {
            count <<= 1;
            right >>= 1;
        }
        return left & count;
    }
};