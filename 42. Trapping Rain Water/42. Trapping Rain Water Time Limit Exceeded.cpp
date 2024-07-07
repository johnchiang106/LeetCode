class Solution {
public:
    int trap(vector<int>& height) {
        int trapped = 0, h = 0;
        for(int i = 1; i < height.size(); ++i) if(height[i] > height[h]) h = i;
        
        while(height[h] > 0){
            int left = -1, right = -1;
            for(int i = 0; i < height.size(); ++i){
                if(height[i] == 0)  continue;
                if(left == -1){
                    left = i;
                }
                else{
                    trapped += i - left - 1;
                    left = i;
                }
                --height[i];
            }
        }
        return trapped;
    }
};