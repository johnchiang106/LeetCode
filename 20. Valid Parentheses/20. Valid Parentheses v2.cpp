class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(auto i:s){
            if(i == '(' || i == '[' || i == '{')	p.push(i);
            else if(p.empty() || (i == ')' && p.top() != '(') || 
            (i == ']' && p.top() != '[') || (i == '}' && p.top() != '{'))	return false;
            else    p.pop();
        }
        return p.empty();
    }
};