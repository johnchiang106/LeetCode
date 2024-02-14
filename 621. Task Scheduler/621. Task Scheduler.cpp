class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count;
        int maxFreq = 0, maxCount = 0, sz = tasks.size();
        for(auto& c: tasks){
            ++count[c];
        }
        for(auto& p: count){
            if(p.second > maxFreq){
                maxFreq = p.second;
                maxCount = 1;
            }
            else if(p.second == maxFreq){
                ++maxCount;
            }
        }
        int ans = (maxFreq - 1) * (n + 1) + maxCount;
        return max(ans, sz);
    }
};