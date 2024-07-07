class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, f = 0, ans;
        for(const auto& p: piles)
            f = max(f,p);
        ans = f;
        while(s <= f){
            // k = (s+f)/2;
            int k = s + (f-s)/2;
            long long hours = 0;
            for(const auto& p: piles){
                hours += ceil((double) p / k);
                if(hours > h)   break;
            }
            
            if(hours <= h){
                ans = min(ans,k);
                f = k-1;
            }
            else
                s = k+1;
        }
        return ans;
    }
};