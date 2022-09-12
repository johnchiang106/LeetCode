class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        const int n = heights.size();
        vector<int> ans(n, 1);
        deque<int> dq;
        dq.push_back(1);
        for(int i = 2; i < n; ++i){
            if(heights[i] > heights[dq.back()])
                dq.push_back(i);
        }
        // for(auto& n: dq)    cout<<n<<", ";
        // cout<<endl;
        for(int i = 0; i < n-1; ++i){
            while(!dq.empty() && i >= dq.front())  dq.pop_front();
            // cout<<i<<": \n";
            // for(auto& n: dq)    cout<<n<<", ";
            // cout<<"\n";
            if(dq.empty()){
                for(int j = i+1; j < n; ++j){
                    if(j == i+1 || heights[j] > heights[dq.back()])
                        dq.push_back(j);
                }
            }
            else{
                int count = 0, f = dq.front();
                for(int j = i+1; j < f; ++j){
                    if(j == i+1 || heights[j] > heights[dq.front()]){
                        dq.push_front(j);
                        ++count;
                    }
                }
                reverse(dq.begin(),dq.begin()+count);
            }
            // for(auto& n: dq)    cout<<n<<", ";
            // cout<<"\n";
            int j;
            for(j = 0; j < dq.size(); ++j){
                // cout<<heights[i]<<" "<<heights[dq[j]]<<endl;
                if(heights[i] < heights[dq[j]])
                    break;
            }
            if(heights[i] > heights[dq.back()])    --j;
            ans[i] = j+1;
            // cout<<"\t"<<ans[i]<<endl;
            // cout<<endl;
        }
        ans[n-1] = 0;
        return ans;
    }
};