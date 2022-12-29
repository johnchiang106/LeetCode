class Solution {
public:
    #define pair_i_d pair<int, double>
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair_i_d> cars;
        const int s = pos.size();
        cars.reserve(s);

        for (int i = 0; i < s; i++)
            cars.push_back({pos[i],(double)(target - pos[i]) / speed[i]});

        sort(cars.begin(),cars.end(), [](pair_i_d a, pair_i_d b){
            return a.first > b.first;
        });

        int ans = 0; double maxTime = 0;
        for (const auto& it : cars)
            if (it.second > maxTime)
                maxTime = it.second, ++ans;
        return ans;
    }
};