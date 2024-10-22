class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        mp.resize(hasApple.size());
        for(auto& edge: edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        return 2*dfs(0, -1, hasApple);
    }
private:
    vector<vector<int>> mp;
    int dfs(int child, int parent, vector<bool>& hasApple){
        int count = 0;
        for(const int& ch: mp[child]){
            if(ch == parent)    continue;
            count += dfs(ch, child, hasApple);
        }
        if(parent != -1 && (hasApple[child] || count > 0)) ++count;
        return count;
    }
};