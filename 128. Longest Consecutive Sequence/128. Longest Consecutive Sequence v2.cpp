class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        for(int& n: nums){
            if(mp.find(n) != mp.end())  continue;
            if(mp.find(n-1) != mp.end()){
                if(mp[n-1] >= n) continue;
                int start = mp[n-1];
                if(mp.find(n+1) != mp.end()){
                    if(mp[n+1] <= n) continue;
                    int end = mp[n+1];
                    mp[start] = end;
                    mp[end] = start;
                    if(start != n-1)
                        mp.erase(n-1);
                    if(end != n+1)
                        mp.erase(n+1);
                }
                else{
                    mp[n] = start;
                    mp[start] = n;
                    if(start != n-1)
                        mp.erase(n-1);
                }
            }
            else if(mp.find(n+1) != mp.end()){
                if(mp[n+1] <= n) continue;
                int end = mp[n+1];
                mp[n] = end;
                mp[end] = n;
                if(end != n+1)
                    mp.erase(n+1);
            }
            else{
                mp[n] = n;
            }
        }
        int ans = 0;
        for(auto& p: mp){
            if(p.first > p.second)  continue;
            ans = max(ans, p.second - p.first + 1);
        }
        return ans;
    }
private:
    unordered_map<int,int> mp;
};