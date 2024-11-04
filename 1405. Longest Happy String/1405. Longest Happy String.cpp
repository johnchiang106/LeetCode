class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        ans.reserve(a+b+c);
        priority_queue<pair<int, char>> pq;
        if(a > 0)   pq.emplace(a,'a');
        if(b > 0)   pq.emplace(b,'b');
        if(c > 0)   pq.emplace(c,'c');
        queue<pair<int, char>> q;
        while(!pq.empty()){
            int n = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            if(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
            if(n > 1){
                if(!ans.empty() && ans.back() == ch){
                    q.emplace(n-1, ch);
                }
                else{
                    pq.emplace(n-1, ch);
                }
            }
            ans.push_back(ch);
        }
        return ans;
    }
};