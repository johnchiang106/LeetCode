class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int count = n-1;
        if(edges.size() < count)    return -1;
        bitset<100> win;
        win.set();
        for(int i = edges.size()-1; i >= 0; --i){
            if(win[edges[i][1]]){
                --count;
                win.reset(edges[i][1]);
            }
            if(i < count)
                return -1;
        }
        for(int i = 0; i < n; ++i){
            if(win[i])  return i;
        }
        return -1;
    }
};