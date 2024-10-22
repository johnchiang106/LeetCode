class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0, ans = 0, s = fruits.size();
        unordered_map<int,int> um;
        for(; j < s; ++j){
            ++um[fruits[j]];
            if(um[fruits[j]] > 1 || um.size() <= 2)
                continue;
            ans = max(ans, j-i);
            while(--um[fruits[i++]] > 0);
            um.erase(fruits[i-1]);
        }
        ans = max(ans, j-i);
        return ans;
    }
};