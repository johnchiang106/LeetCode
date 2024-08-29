class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > on, off;
        for(auto& trip: trips){
            on.emplace(trip[1], trip[0]);
            off.emplace(trip[2], trip[0]);
        }
        while(!on.empty()){
            if(on.top().first < off.top().first){
                capacity -= on.top().second;
                if(capacity < 0)    return false;
                on.pop();
            }
            else{
                capacity += off.top().second;
                off.pop();
            }
        }
        return true;
    }
};