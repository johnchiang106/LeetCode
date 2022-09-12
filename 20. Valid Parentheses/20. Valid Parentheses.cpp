class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for(auto iter = s.begin(); iter != s.end(); ++iter){
            if(*iter == '(' || *iter == '[' || *iter == '{')	parentheses.push(*iter);
            else if(parentheses.empty())	return false;
            else{
                char &tmp = parentheses.top();
                if((tmp == '(' && *iter == ')') || (tmp == '[' && *iter == ']') || (tmp == '{' && *iter == '}'))
                    parentheses.pop();
                else	return false;
            }
        }
        return parentheses.empty();
    }
};