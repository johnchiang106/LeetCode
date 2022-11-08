class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        // if(finalSum % 2 == 1)   return ans;
        if(finalSum & 1)   return ans;
        long long remain = finalSum, curr = 2;
        while(remain > 0){
            if(remain >= curr){
                remain -= curr;
                ans.push_back(curr);
            }
            else{
                curr = ans.back();
                remain += curr;
                ans.pop_back();
            }
            curr += 2;
        }
        return ans;
    }
};