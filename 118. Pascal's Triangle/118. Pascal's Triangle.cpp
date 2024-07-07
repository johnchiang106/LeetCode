class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.reserve(n);
        ans.push_back(vector<int>{1});
        for(int i = 0; i < n-1; ++i){
            vector<int> temp;
            temp.reserve(i+2);
            temp.push_back(1);
            for(int j = 0; j < i; ++j)
                temp.push_back(ans.back()[j] + ans.back()[j+1]);
            temp.push_back(1);
            ans.push_back(temp);
        }
    return ans;
    }
};