class Solution {
public:
    int calculate(string s) {
        int ans = 0, ss = s.size(), sign = 1;
        stack<pair<int,int>> st;
        for(int i = 0; i < ss; ++i){
            if(s[i] == ' ' || s[i] == '+')    continue;
            if(isdigit(s[i])){
                string number(1, s[i]); 
                while(isdigit(s[++i]))  number += s[i];
                ans += stoi(number) * sign;
                sign = 1;
                --i;
            }
            else if(s[i] == '('){
                st.push({ans, sign});
                ans = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                ans = st.top().first + st.top().second * ans;
                st.pop();
            }
            else if(s[i] == '-'){
                sign *= -1;
            }
        }
        return ans;
    }
};