class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.front() >= 0 || nums.back() <= 0){
            if(nums.back() <= 0)  reverse(nums.begin(),nums.end());
            for(auto& n: nums)  n = n*n;
            return nums;
        }
        else{
            auto it = find_if(nums.begin(),nums.end(),[](int n){
                return n >= 0;
            });
            vector<int> v(nums.size(),0);
            auto i = it-1, j = it, k = v.begin();
            while(i >= nums.begin() && j != nums.end()){
                if(-(*i) > *j){
                    *k = (*j) * (*j);
                    ++j;
                }
                else{
                    *k = (*i) * (*i);
                    --i;
                }
                ++k;
            }
            while(i >= nums.begin()){
                *k = (*i) * (*i);
                --i, ++k;
            }
            while(j != nums.end()){
                *k = (*j) * (*j);
                ++j, ++k;
            }
            return v;
        }
    }
};