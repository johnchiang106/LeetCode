class MinStack {
    private Stack<Integer> st = new Stack<>();
    private Stack<int[]> minSt = new Stack<>();

    public MinStack() {}
    
    public void push(int val) {
        st.push(val);
        if(minSt.empty() || minSt.peek()[0] > val){
            minSt.push(new int[]{val,1});
        }
        else if(minSt.peek()[0] == val){
            ++minSt.peek()[1];
        }
    }
    
    public void pop() {
        if(minSt.peek()[0] == st.peek() && --minSt.peek()[1] == 0){
            minSt.pop();
        }
        st.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return minSt.peek()[0];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.peek();
 * int param_4 = obj.getMin();
 */