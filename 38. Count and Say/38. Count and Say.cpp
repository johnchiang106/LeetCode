class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        while(--n > 0){
            string str2;
            int count = 1, s = str.size();
            str2.reserve(s * 2);
            for(int i = 0; i < s; ++i){
                if(i == s-1 || str[i] != str[i+1]){
                    str2 += to_string(count);
                    str2.push_back(str[i]);
                    count = 1;
                }
                else    ++count;
            }
            str = str2;
        }
        return str;
    }
};