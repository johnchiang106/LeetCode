class Solution {
public:
    string decodeString(string s) {
        stack<int> st1;
        stack<string> st2;
        st2.push("");
        int n = s.size();
        for(int i = 0; i < n; ++i){
            if(s[i] >= '0' && s[i] <= '9'){
                size_t f = s.find_first_not_of("0123456789", i);
                // string temp = "";
                // do  temp += s[i++];
                // while(s[i] >= '0' && s[i] <= '9');
                st1.push(stoi(s.substr(i,f)));
                i = f;
            }
            if(s[i] == ']'){
                string temp = st2.top();
                st2.pop();
                for(int i = st1.top(); i > 0; --i)
                    st2.top() += temp;
                st1.pop();
            }
            else if(s[i] == '['){
                st2.push("");
            }
            else{
                st2.top().push_back(s[i]);
            }
        }
        return st2.top();
    }
};