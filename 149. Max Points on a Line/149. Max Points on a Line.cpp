class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int max_points = 0;

        for(int i = 0; i < n; ++i){
            unordered_map<float, int> mp;
            int parallel = 1;
            for(int j = i+1; j < n; ++j){
                if(points[i][0]==points[j][0])
                    ++parallel;
                else{
                    float slope = (points[j][1]-points[i][1])/(float)(points[j][0]-points[i][0]);
                    ++mp[slope];
                }
            }
            int points_count = 0;
            for(auto& it : mp)
                points_count = max(points_count, it.second);

            max_points = max(parallel, max(points_count + 1, max_points));
        }

        return max_points;
    }
};