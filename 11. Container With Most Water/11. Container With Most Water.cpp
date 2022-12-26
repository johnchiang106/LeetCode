class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, maxA = 0;
        while(l < r){
            maxA = max(maxA, (r-l) * min(height[l],height[r]));
            if(height[l] < height[r])   ++l;
            else    --r;
        }
        return maxA;
    }
// private:
//     int area(const int& l, const int& r, const vector<int>& height) {
//         return (r-l) * min(height[l],height[r]);
//     }
};