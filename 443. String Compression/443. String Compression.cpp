class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() <= 1)   return 1;
        int i = 0;
        for(int j = 1, k = 0; j <= chars.size(); j++){
            if(j == chars.size() || chars[k] != chars[j]){
                chars[i] = chars[k];
                if(k != j-1)
                    for(char digit : to_string(j-k))
                        chars[++i] = digit;
                ++i;
                k = j;
            }
        }
        return i;
    }
};