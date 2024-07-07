class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        stable_partition(begin(nums),end(nums),[](int& i){return i;});
        //stable_partition(rbegin(nums),rend(nums),logical_not<int>());
    }
};