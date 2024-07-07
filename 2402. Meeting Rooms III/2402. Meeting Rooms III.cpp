class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<int>> rooms;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> wait;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> occupied;
        for(int i = 1; i < n; ++i){
            rooms.push(i);
        }
        for(auto& vec: meetings){
            wait.push({vec[0], vec[1]});
        }
        ++count[0];
        occupied.push({wait.top().second,0});
        wait.pop();
        while(!wait.empty()){
            while(!occupied.empty() && occupied.top().first <= wait.top().first){
                rooms.push(occupied.top().second);
                occupied.pop();
            }
            if(rooms.empty() && !occupied.empty()){
                ++count[occupied.top().second];
                occupied.push({wait.top().second - wait.top().first + occupied.top().first, occupied.top().second});
                occupied.pop();
                wait.pop();
            }
            while(occupied.empty() || (!rooms.empty() && occupied.top().first > wait.top().first)){
                ++count[rooms.top()];
                occupied.push({wait.top().second, rooms.top()});
                rooms.pop();
                wait.pop();
                if(wait.empty())
                    break;
            }
        }
        int ans = 0, m = -1;
        for(int i = 0; i < n; ++i){
            if(count[i] > m){
                m = count[i];
                ans = i;
            }
        }
        return ans;
    }
};