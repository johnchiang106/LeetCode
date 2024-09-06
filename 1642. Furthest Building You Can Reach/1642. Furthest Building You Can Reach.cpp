class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int s = heights.size();
        if(s <= 1)  return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i = heights.begin()+1; i != heights.end(); ++i){
            int diff = *i - *(i-1);
            if(diff <= 0)  continue;
            pq.emplace(diff);
            if(pq.size() > ladders){
                bricks -= pq.top();
                if(bricks < 0)  return i-1-heights.begin();
                pq.pop();
            }
        }
        return s-1;
    }
};