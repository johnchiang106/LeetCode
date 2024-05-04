class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        const int n = spells.size(), m = potions.size();
        vector<int> ans(n,-1);
        for(int i = 0; i < n; ++i){
            long long fac = ceil(success / double(spells[i]));
            int start = 0, end = m-1, mid;
            while(start <= end){
                mid = start + (end - start) / 2;
                if(potions[mid] < fac){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            ans[i] = m-start;
        }
        return ans;
    }
};