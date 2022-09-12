class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int n = points.size();
        if(n <= k)  return points;
        
        sort(points.begin(),points.end(),[](vector<int>& v1, vector<int>& v2){
            if(v1.size() < 2 || v2.size() < 2)  return true;
            return v1[0]*v1[0] + v1[1]*v1[1] < v2[0]*v2[0] + v2[1]*v2[1];
        });
        
        return vector<vector<int>> (points.begin(),points.begin()+k);
    }
};