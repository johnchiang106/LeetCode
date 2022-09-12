class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int s = nums.size();
        if(s <= 1)    return 0;
        int large = 0, small = INT_MAX, ans = 0;
        for(auto& n: nums)
            large = max(large,n), small = min(small,n);
        if(large == small)  return 0;
        double len = (large-small)/(s-1.0);
        // cout<<"large: "<<large<<", small: "<<small<<", len: "<<len<<endl;
        vector<pair<int,int>> buckets(s,{-1,-1});
        for(auto& n: nums){
            int i = (n-small)/len;
            // cout<<n<<", "<<i<<endl;
            if(buckets[i].first == -1)
                buckets[i].first = n, buckets[i].second = n;
            else if(n > buckets[i].first)    buckets[i].first = n;
            else if(n < buckets[i].second)    buckets[i].second = n;
        }
        large = -1;
        for(auto& p: buckets){
            if(p.first == -1)   continue;
            if(large != -1)
                ans = max(ans,p.second-large);
            large = p.first, small = p.second;
        }
        return ans;
    }
};