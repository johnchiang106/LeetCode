class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        int stars = 0;
        for(auto i = s.rbegin(); i != s.rend(); ++i){
            if(*i == '*')   ++stars;
            else if(stars > 0) --stars;
            else    ans.push_back(*i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};