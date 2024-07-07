class Solution {
public:
    int calculate(string s) {
        int ss = s.size();
        stack<int> nums;
        stack<char> oper;
        for(int i = 0; i < ss; ++i){
            if(s[i] == ' ')    continue;
            if(!isdigit(s[i])){
                oper.push(s[i]);
                continue;
            }
            string number(1, s[i]); 
            while(isdigit(s[++i]))  number += s[i];
            --i;

            if(oper.empty() || oper.top() == '+' || oper.top() == '-'){
                nums.push(stoi(number));
                continue;
            }
            int temp = (oper.top() == '*') ? nums.top() * stoi(number) : nums.top() / stoi(number);
            nums.pop();
            oper.pop();
            nums.push(temp);
        }
        int n = 0;
        while(!oper.empty()){
            int temp = (oper.top() == '+') ? nums.top() : -nums.top();
            n += temp;
            nums.pop();
            oper.pop();
        }
        if(!nums.empty())   n += nums.top();
        return n;
    }
};