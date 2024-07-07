class Solution {
public:
    int minPairSum(vector<int>& nums) {
        char arr[100001] = {0};
        for(const auto& i: nums)
            ++arr[i];
        int i = 0, j = 100000, ma = 0;
        while(i <= j){
            if(arr[i] == 0)
                ++i;
            else if(arr[j] == 0)
                --j;
            else{
                ma = max(ma, i+j);
                --arr[i], --arr[j];
            }
        }
        return ma;
    }
};