class Solution {
public:
    int trap(vector<int>& height) {
        const auto hsize = height.size();
        if(hsize <= 2)   return 0;
  
        int ans = 0;
        vector<pair<int,int>> v;
        v.reserve(hsize);

        for(int i = 0; i < hsize; ++i)
            if(height[i] != 0)  v.push_back({height[i],i});
        
        const auto vsize = v.size();
        if(v.size() <= 1)   return 0;

        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first > b.first;
        });

        int p1 = v[0].second, p2 = p1;
        for(int i = 1; i < vsize; ++i){
            int& p3 = v[i].second;
            if(p1 < p3 && p3 < p2)  continue;

            if(p3 < p1){
                if(p3+1 != p1){
                ans += height[p3] * (p1-p3-1);
                for(int j = p3 + 1; j < p1; ++j)
                    ans -= height[j];
                }
                p1 = p3;
            }
            else if(p3 > p2){
                if(p2+1 != p3){
                ans += height[p3] * (p3-p2-1);
                for(int j = p2 + 1; j < p3; ++j)
                    ans -= height[j];
                }
                p2 = p3;
            }

            if(p1 == 0 && p2 == hsize-1)  break;
        }

        return ans;
    }
};