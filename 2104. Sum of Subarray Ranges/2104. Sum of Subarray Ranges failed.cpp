class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return helper(nums,0,nums.size());
    }
    long long helper(vector<int>& nums, int start, int end){
        if(start >= end-1)    return 0;
        cout<<start<<", "<<end<<"  /  ";
        long long sum = 0;
        pair<int,int> subRange;
        int s2, e2;
        subRange = {nums[start],nums[start]};
        for(int i = start+1; i < end; ++i){
            if(subRange.first > nums[i]){
                subRange.first = nums[i];
                s2 = i;
            }
            else if(subRange.second < nums[i]){
                subRange.second = nums[i];
                e2 = i;
            }
        }
        cout<<s2<<", "<<e2<<endl;
        sum += (s2-start+1)*(end-e2);
        cout<<"sum1: "<<endl;
        sum += helper(nums,start,e2);
        cout<<"sum2: "<<endl;
        sum += helper(nums,s2+1,e2);
        cout<<"sum3: "<<endl;
        sum += helper(nums,s2+1,end);
        cout<<"sum4: "<<endl;
        return sum;
    }
};