class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(const auto& ch: s)
            c ^= ch;
        for(const auto& ch: t)
            c ^= ch;
        return c;
    }
};