class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        sort(weights.begin(), weights.end());
        int s = weights.size(), left = weights[s-1], right = left * ceil(s/(float)days), mid;
        while(left <= right){
            mid = left + (right-left)/2;
            if(sufficientCapacity(weights, days, s, mid))   right = mid-1;
            else    left = mid+1;
            printf("\n%i %i\n", left, right);
        }
        return right+1;
    }
private:
    bitset<50000> taken;
    bool sufficientCapacity(vector<int>& weights, int days, const int& s, int& mid){
        printf("%i \n", mid);
        taken.reset();
        while(days-- > 0){
            int w = mid;
            for(int i = s-1; i >= 0; --i){
                if(!taken[i] && w >= weights[i]){
                    w -= weights[i];
                    taken.set(i);
                    printf("%i ", i);
                    if(w < weights[0])  break;
                }
            }
            printf("d%i\n", days);
            if(taken.count() == s) return true;
        }
        return false;
    }
};