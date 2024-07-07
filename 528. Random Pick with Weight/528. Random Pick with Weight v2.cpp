class Solution {
public:
    Solution(vector<int>& w) {
        const int n = w.size();
        acc.reserve(n);
        acc.push_back(w.front());
        for(int i = 1; i < n; ++i)
            acc.push_back(acc.back()+w[i]);
    }
    
    int pickIndex() {
        int x = rand() % acc.back();
        if(x < acc.front())
            return 0;
        
        int high = acc.size()-1, low = 1;
        while(high > low){
            int mid = (high+low)/2;
            if(acc[mid] > x && acc[mid-1] <= x)
                return mid;
            else if(acc[mid-1] > x)
                high = mid-1;
            else
                low = mid+1;
        }
        return high;
    }
private:
    vector<int> acc;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */