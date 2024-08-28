class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        ans.reserve(intervals.size());
        auto it = intervals.begin();
        while(it != intervals.end()){
            if(newInterval[1] < (*it)[0]){
                ans.push_back(newInterval);
                copy(it, intervals.end(), back_inserter(ans));
                return ans;
            }
            if((*it)[1] < newInterval[0]){
                ans.push_back(*it);
            }
            else{
                newInterval[0] = min(newInterval[0], (*it)[0]);
                newInterval[1] = max(newInterval[1], (*it)[1]);
            }
            ++it;
        }
        ans.push_back(newInterval);
        return ans;
    }
};