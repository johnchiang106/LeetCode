class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        vector<int> mp(26,0);
        for(char& ch: s)
            ++mp[ch-'a'];
        for(int i = 0; i < 26; ++i)
            if(mp[i] != 0)
                pq.emplace(mp[i], 'a'+i);
        
        string ans = "";
        while(!pq.empty()){
            int count = pq.top().first;
            char ch = pq.top().second;
            ans += ch;
            pq.pop();
            if(--count > 0 && pq.empty())   return "";
            if(!pq.empty()){
                int count2 = pq.top().first-1;
                ans += pq.top().second;
                pq.pop();
                if(count2 > 0)
                    pq.emplace(count2, ans.back());
            }
            if(count > 0)
                pq.emplace(count, ch);
        }
        return ans;
    }
};