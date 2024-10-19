class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> wait;
        for(int i = 0; i < tasks.size(); ++i){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        vector<int> ans;
        ans.reserve(tasks.size());
        int currTime = tasks[0][0];
        for(int i = 0; i < tasks.size();){
            if(tasks[i][0] <= currTime || wait.empty()){
                if(wait.empty()){
                    currTime = max(currTime, tasks[i][0]);
                }
                wait.emplace(tasks[i][1], tasks[i][2]);
                ++i;
            }
            else{
                ans.push_back(wait.top().second);
                currTime += wait.top().first;
                wait.pop();
            }
        }
        while(!wait.empty()){
            ans.push_back(wait.top().second);
            wait.pop();
        }
        return ans;
    }
};