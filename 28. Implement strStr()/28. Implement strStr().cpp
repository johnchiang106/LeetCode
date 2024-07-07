class Solution {
public:
    int strStr(string haystack, string needle) {
        string::iterator i = haystack.begin(), j = needle.begin();
        
        while(haystack.end() - i >= needle.end() - j && i != haystack.end()){
            if(*i == *j){
                ++j;
                if(j == needle.end())
                    return i - haystack.begin() + 1 - needle.size();
            }
            else if(j != needle.begin()){
                i -= j - needle.begin();
                j = needle.begin();
            }
            ++i;
        }
        return -1;
    }
};