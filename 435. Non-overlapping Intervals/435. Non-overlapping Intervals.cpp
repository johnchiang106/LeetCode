class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] != b[0])    return a[0] < b[0];
            return a[1] > b[1];
        });
        auto prev = intervals.begin();
        int ans = 0;
        for(auto it = intervals.begin()+1; it != intervals.end(); ++it){
            if((*it)[0] < (*prev)[1]){
                ++ans;
                if((*it)[1] < (*prev)[1])
                    prev = it;
            }
            else{
                prev = it;
            }
        }
        return ans;
    }
};