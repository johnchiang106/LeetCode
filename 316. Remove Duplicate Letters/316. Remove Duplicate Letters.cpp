class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        int lastPosition[26] = {-1};
        bool seen[26] = {false};
        for (int i = 0; i < s.size(); ++i)
            lastPosition[s[i] - 'a'] = i;
        for(int i = 0; i < s.size(); ++i){
            if(seen[s[i]-'a']) continue;
            while(!st.empty() && s[i] <= st.top() && lastPosition[st.top() - 'a'] > i){
                seen[st.top()-'a'] = false;
                st.pop();
            }
            seen[s[i]-'a'] = true;
            st.push(s[i]);
        }
        s.resize(st.size());
        for(auto it = s.rbegin(); it != s.rend(); ++it){
            *it = st.top();
            st.pop();
        }
        return s;
    }
};