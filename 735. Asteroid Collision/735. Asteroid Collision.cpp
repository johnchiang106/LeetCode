class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        ans.reserve(asteroids.size());
        for(int& a: asteroids){
            if(ans.empty() || ans.back() < 0 || a > 0){
                ans.push_back(a);
                continue;
            }
            while(!ans.empty() && ans.back() > 0 && -a > ans.back())  ans.pop_back();
            if(!ans.empty() && -a == ans.back())    ans.pop_back();
            else if(ans.empty() || ans.back() < 0)    ans.push_back(a);
        }
        return ans;
    }
};