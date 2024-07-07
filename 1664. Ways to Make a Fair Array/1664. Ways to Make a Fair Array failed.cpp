class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int ans = 0, s = nums.size();
        if(s == 1)  return 1;
        vector<int> prefix(s,0);
        prefix[0] = nums[0];
        prefix[1] = nums[1];
        for(int i = 2; i < s; ++i){
            prefix[i] = prefix[i-2] + nums[i];
        }
        int oddLast = s-1, evenLast = s-1;

        if(s & 1){
            --oddLast;
            if(prefix[evenLast] - prefix[0] == prefix[oddLast])
                ++ans;
        }
        else{
            --evenLast;
            if(prefix[oddLast] - prefix[0] == prefix[evenLast])
                ++ans;
        }

        if(prefix[evenLast] - prefix[0] == prefix[oddLast] - prefix[1] + prefix[0])
            ++ans;
        
        for(int i = 2; i < s; ++i){
            if(i & 1){
                if(prefix[oddLast] - prefix[i] + prefix[i-1] == prefix[evenLast] - prefix[i-1] + prefix[i-2])
                    ++ans;
            }
            else{
                if(prefix[oddLast] - prefix[i-1] + prefix[i-2] == prefix[evenLast] - prefix[i] + prefix[i-1])
                    ++ans;
            }
        }
        return ans;
    }
};

/*
0 1 2 3 4 5 6 7 8 9

remove 4
i9 - i3 + i2
i8 - i4 + i3

remove 5
i9 - i5 + i4
i8 - i4 + i3
*/