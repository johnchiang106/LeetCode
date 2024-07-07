class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.reserve(n);
        ans.push_back(vector<int>{1});
        for(int i = 1; i < n; ++i){
            vector<int> temp;
            temp.reserve(i+1);
            temp.push_back(1);
            for(int j = 1; j <= i; ++j){
                if(j <= i/2) temp.push_back(ans.back()[j-1] + ans.back()[j]);
                else    temp.push_back(temp[i-j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};