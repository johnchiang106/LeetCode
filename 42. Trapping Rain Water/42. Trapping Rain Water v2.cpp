class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2)   return 0;
  
        int trapped = 0;
        vector<pair<int,int>> v;

        for(int i = 0; i < height.size(); ++i)
            if(height[i] != 0)  v.push_back({height[i],i});
        if(v.size() <= 1)   return 0;
        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first > b.first;
        });

        int p1 = v[0].second, p2 = p1;
        for(int i = 1; i < v.size(); ++i){
            int p3 = v[i].second;
            if(p1 < p3 && p3 < p2)  continue;

            int t = height[p3];
            if(p3 < p1){
              if(p3+1 != p1){
                t *= p1-p3-1;
                for(int j = p3 + 1; j < p1; ++j)
                  t -= height[j];
                trapped += t;
              }
              p1 = p3;
            }
            else if(p3 > p2){
              if(p3-1 != p2){
                t *= p3-p2-1;
                for(int j = p2 + 1; j < p3; ++j)
                  t -= height[j];
                trapped += t;
              }
              p2 = p3;
            }
            // cout<<trapped<<endl;

            if(p1 == 0 && p2 == height.size()-1)  break;
        }

        return trapped;
    }
};