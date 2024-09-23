class Solution {
public:
    string intToRoman(int num) {
        string n = to_string(num), ans = "";
        int i = n.size() * 2 - 2;
        char symbols[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        for(char& ch: n){
            if(ch == '4'){
                ans.push_back(symbols[i]);
                ans.push_back(symbols[i+1]);
            }
            else if(ch == '9'){
                ans.push_back(symbols[i]);
                ans.push_back(symbols[i+2]);
            }
            else{
                if(ch > '4'){
                    ans.push_back(symbols[i+1]);
                    ch -= 5;
                }
                while(ch-- > '0')
                    ans.push_back(symbols[i]);
            }
            i -= 2;
        }
        return ans;
    }
};