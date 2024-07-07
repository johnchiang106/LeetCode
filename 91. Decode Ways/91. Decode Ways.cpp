class Solution {
public:
    int numDecodings(string s) {
        if(s.front() == '0')    return 0;
        int ss = s.size();
        int left = 1, right = 1;
        for(int i = 1; i < ss; ++i){
            if(s[i] == '0'){
                if(s[i-1] != '1' && s[i-1] != '2')
                    return 0;
                continue;
            }
            if(i == ss-1 || s[i+1] != '0')
                if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')){
                    int temp = right;
                    right += left;
                    left = temp;
                }
            else    left = right;
        }
        return right;
    }
};