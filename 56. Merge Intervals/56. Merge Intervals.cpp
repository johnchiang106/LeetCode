class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] != b[0])    return a[0] < b[0];
            return a[1] > b[1];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(vector<int>& curr: intervals){
            vector<int>& prev = ans.back();
            if(curr[0] <= prev[1]){
                prev[1] = max(prev[1], curr[1]);
            }
            else{
                ans.push_back(curr);
            }
        }
        return ans;
    }
};