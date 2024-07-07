class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)  return x;
        int low = 1, high = x/2;
        while(true){
            int mid = (low+1)/2 + high/2;
            if(mid <= x / mid && mid+1 > x / (mid+1))
                return mid;
            if(mid > x / mid)   high = mid-1;
            else    low = mid+1;
        }
    }
};