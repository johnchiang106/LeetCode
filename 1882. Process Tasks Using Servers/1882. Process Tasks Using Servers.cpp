class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        #define pi pair<int,int>
        int s = tasks.size(), q = s;
        auto cmp = [](pi& p1, pi& p2){
            if(p1.first != p2.first)
                return p1.first > p2.first;
            return p1.second > p2.second;
        };
        priority_queue<pi, vector<pi>, decltype(cmp)> serverQ, busyQ;
        for(int i = 0; i < servers.size(); ++i){
            serverQ.emplace(servers[i], i);
        }
        vector<int> ans;
        ans.reserve(s);
        for(int t = 0; t < s; ++t){
            while(!busyQ.empty() && busyQ.top().first <= t){
                serverQ.emplace(servers[busyQ.top().second], busyQ.top().second);
                busyQ.pop();
            }
            int i = min(t, q);
            for(; !serverQ.empty() && i <= t; ++i){
                busyQ.emplace(t+tasks[i], serverQ.top().second);
                ans.push_back(serverQ.top().second);
                serverQ.pop();
            }
            q = i;
        }
        while(q < s){
            int t = busyQ.top().first;
            while(!busyQ.empty() && busyQ.top().first == t){
                serverQ.emplace(servers[busyQ.top().second], busyQ.top().second);
                busyQ.pop();
            }
            while(!serverQ.empty() && q < s){
                busyQ.emplace(t+tasks[q++], serverQ.top().second);
                ans.push_back(serverQ.top().second);
                serverQ.pop();
            }
        }
        return ans;
    }
};