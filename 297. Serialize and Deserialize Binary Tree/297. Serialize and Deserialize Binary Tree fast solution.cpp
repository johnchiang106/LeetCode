// fail to deal with same numbers

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() <= 1)    return 1;
        
        queue<vector<int>> q;
        set<vector<int>> s;
        q.push(nums);
        int largest = 1, count = 0;
        
        while(!q.empty()){
            vector<int> cur = q.front();
            int i = 1, same = 0;
            for(; i < cur.size(); ++i){
                if(cur[i] < cur[i-1]){
                    vector<int> v(cur);
                    auto start = i;
                    while(i < cur.size() && cur[i] < cur[start-1]) ++i;
                    v.erase(v.begin()+start,v.begin()+i);
                    q.push(v);

                    v = cur;
                    i = start-1;
                    while(i >= 0 && cur[i] > cur[start])   --i;
                    v.erase(v.begin()+i+1,v.begin()+start);
                    q.push(v);

                    break;
                }
                else if(cur[i] == cur[i-1]) ++same;
            }
            q.pop();
            if(i == cur.size() && i-same >= largest){
                if(i-same > largest){
                    largest = i - same;
                    s.clear();
                }
                count += same;
                s.insert(cur);
                // cout<<largest<<" "<<i<<" "<<same<<endl;
                // cout<<count<<" "<<q.size()<<endl;
            }
        }
        
        int ans = 0;
        for(auto& v: s){
            int last = 1000000;
            int num = 1, cur = 0;
            for(int i = 1; i < v.size(); ++i){
                if(v[i] == v[i-1]){
                    if(last != v[i]){
                        last = v[i];
                        num *= (cur+1);
                        cur = 0;
                    }
                    cur += 1;
                }
            }
            if(cur > 0) num *= (cur+1);
            ans += num;
        }
        // for(auto& n: q.front()) cout<<n<<" ";
        // cout<<endl;
        return ans;
    }
};