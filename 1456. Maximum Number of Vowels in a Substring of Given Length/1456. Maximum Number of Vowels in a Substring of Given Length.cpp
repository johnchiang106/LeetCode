class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0, j = 0, curr = 0, ss = s.size(), ans = 0;
        while(j < ss){
            if(j-i+1 <= k){
                if(isVowel(s[j]))
                    ++curr;
            }
            else{
                if(isVowel(s[i])){
                    if(!isVowel(s[j]))
                        --curr;
                }
                else if(isVowel(s[j]))
                    ++curr;
                ++i;
            }
            ++j;
            ans = max(ans, curr);
        }
        return ans;
    }
private:
    bool isVowel(char& c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};