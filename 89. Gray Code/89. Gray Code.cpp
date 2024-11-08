class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0, 1};
        ans.reserve(pow(2,n));
        while(--n > 0){
            int num = ans.size();
            for(int i = ans.size()-1; i >= 0; --i)
                ans.push_back(num | ans[i]);
        }
        return ans;
    }
};