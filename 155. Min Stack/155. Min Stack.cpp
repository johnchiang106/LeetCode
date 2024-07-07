class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val < minSt.top().first)
            minSt.push({val,1});
        else if(val == minSt.top().first)
            ++minSt.top().second;
    }
    
    void pop() {
        if(st.top() == minSt.top().first && --minSt.top().second == 0)
            minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top().first;
    }
private:
    stack<int> st;
    stack<pair<int,int>> minSt;
};