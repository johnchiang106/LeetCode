class Solution {
public:
    long long calc(long long  n)
    {
    return (long long) ((-1 + sqrt(1 + 4 * n)) / 2);
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long>ans;
        
        if(finalSum&1)
            return ans;
        
        long long sum=0;
        long long make=calc(finalSum);
        make--;
        for(long long i=2;make--;i+=2)
        {
            if(i+sum<=finalSum)
            {
                sum+=i;
                ans.push_back(i);
            }
        }
        ans.push_back(finalSum-sum);
        return ans;
        
    }
};