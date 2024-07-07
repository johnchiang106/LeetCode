class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = weights.size(), left = weights[s-1], right, mid;
        for(int& w: weights)
            right = max(right,w);
        right *= ceil(s/(float)days);
        while(left <= right){
            mid = left + (right-left)/2;
            if(sufficientCapacity(weights, days, s, mid))   right = mid-1;
            else    left = mid+1;
        }
        return right+1;
    }
private:
    bool sufficientCapacity(vector<int>& weights, int days, const int& s, int mid){
        int remain = 0;
        while(days-- > 0){
            int w = mid;
            for(int i = remain; i < s; ++i){
                if(w >= weights[i]){
                    if(i == s-1)    return true;
                    w -= weights[i];
                }
                else{
                    remain = i;
                    break;
                }
            }
        }
        return false;
    }
};