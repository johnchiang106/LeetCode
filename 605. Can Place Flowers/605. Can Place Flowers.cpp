class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        const int s = flowerbed.size();
        if(n <= 0)  return true;
        if(s == 1)  return n <= 1 && flowerbed[0] == 0;
        
        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            if(--n == 0) return true;
        }
        for(int i = 1; i < s-1; ++i){
            if(flowerbed[i-1] == 1 || flowerbed[i] == 1 || flowerbed[i+1] == 1)
                continue;
            
            flowerbed[i++] = 1;
            if(--n == 0) return true;
        }
        if(flowerbed[s-2] == 0 && flowerbed.back() == 0)
            --n;
        return n <= 0;
    }
};