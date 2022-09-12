class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& t: tokens){
            if(t[0] < '0' && t.size() == 1){
                int b = st.top();   st.pop();
                int a = st.top();   st.pop();
                switch(t[0]){
                    case '*':    a *= b;    break;
                    case '+':    a += b;    break;
                    case '-':    a -= b;    break;
                    case '/':    a /= b;    break;
                    default:    break;
                }
                st.push(a);
            }
            else    st.push(stoi(t));
        }
        return st.top();
    }
};