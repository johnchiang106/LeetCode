class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        auto po = popped.begin();
        for(auto pu = pushed.begin(); pu != pushed.end(); ++pu){
            if(*po == *pu){
                ++po;
                continue;
            }
            while(!st.empty() && st.top() == *po){
                st.pop();
                ++po;
            }
            st.push(*pu);
        }
        while(!st.empty() && st.top() == *po){
            st.pop();
            ++po;
        }
        return st.empty();
    }
};