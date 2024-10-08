class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int count = 32; count > 0; --count){
            ans <<= 1;
            if(n & 1){
                ans |= 1;
            }
            n >>= 1;
        }
        return ans;
    }
};