class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size()-1, i = 0, miss = arr[0]-1, curr = arr[0];
        if(miss >= k){
            curr = 0, miss = 0;
        }
        while(++i <= n){
            while(miss < k && ++curr != arr[i])
                ++miss;
        }
        while(miss < k)
            ++miss, ++curr;
        return curr;
    }
};