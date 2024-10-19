class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, s = colors.size(), ans = 0;
        while(++i < s){
            if(colors[i] == colors[i-1]){
                int t = neededTime[i] + neededTime[i-1];
                int ma = max(neededTime[i], neededTime[i-1]);
                while(++i < s && colors[i] == colors[i-1]){
                    t += neededTime[i];
                    ma = max(neededTime[i], ma);
                }
                ans += t - ma;
            }
        }
        return ans;
    }
};