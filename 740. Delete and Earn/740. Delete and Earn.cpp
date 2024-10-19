class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> count;
        for(int& n: nums){
            ++count[n];
        }
        
        for(auto& p: count){
            int p0 = 0, p1 = 0, curr = p.first;
            if(p.second == 0)   continue;
            while(count.find(--curr) != count.end());
            ++curr;

            while(count.find(curr) != count.end()){
                int temp = max(p0 + curr * count[curr], p1);
                p0 = p1;
                p1 = temp;
                count[curr] = 0;
                ++curr;
            }
            ans += max(p0, p1);
        }
        return ans;
    }
};