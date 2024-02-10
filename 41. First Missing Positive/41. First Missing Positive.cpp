class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int small = 0;
        // priority_queue<int, vector<int>, greater<int>> large;
        auto comparator = [](int a, int b) { return a < b; };
        set<int, decltype(comparator)> large(comparator);
        for(auto& n: nums){
            if(n > small + 1){
                large.insert(n);
            }
            if(n == small + 1){
                ++small;
                if(!large.empty()){
                    while(small == *large.begin() - 1){
                        large.erase(large.begin());
                        ++small;
                    }
                }
            }
        }
        return small + 1;
    }
};