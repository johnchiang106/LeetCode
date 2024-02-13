class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        auto heavy = people.end() - 1, light = people.begin();
        while(heavy >= light){
            if(*heavy + *light <= limit)
                ++light;
            --heavy, ++ans;
        }
        return ans;
    }
};