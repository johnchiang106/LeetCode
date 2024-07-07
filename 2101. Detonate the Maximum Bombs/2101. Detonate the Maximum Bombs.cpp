class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        const int n = bombs.size();
        for (int i = 0; i < n; ++i) {
            denotate[i] = unordered_set<int>();
        }
        for(int i = 0; i < n-1; ++i){
            for(int j = i+1; j < n; ++j){
                pair<bool, bool> a = affect(bombs[i], bombs[j]);
                if(a.first) denotate[i].insert(j);
                if(a.second) denotate[j].insert(i);
            }
            denotate[i].insert(i);
        }
        denotate[n-1].insert(n-1);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            queue<int> q;
            unordered_set<int> searched;
            searched.insert(i);
            for(const int& j: denotate[i])
                q.push(j);
            dfs(searched, q, i);
            ans = max(ans, int(searched.size()));
        }
        return ans;
    }
private:
    unordered_map<int, unordered_set<int>> denotate;
    pair<bool,bool> affect(vector<int>& b1, vector<int>& b2){
        int& x1 = b1[0], y1 = b1[1], r1 = b1[2];
        int& x2 = b2[0], y2 = b2[1], r2 = b2[2];
        long long sq = (long long)(x2-x1)*(x2-x1) + (long long)(y2-y1)*(y2-y1);
        return {sq <= (long long)r1 * r1, sq <= (long long)r2 * r2};
    }
    void dfs(unordered_set<int>& st, queue<int>& q, const int& i){
        for(const int& j: denotate[i]){
            if(st.find(j) == st.end()){
                st.insert(j);
                dfs(st, q, j);
            }
        }
        return;
    }
};