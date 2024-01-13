class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for(Character c: s.toCharArray()){
            if(c == '{' || c == '[' || c == '('){
                st.push(c);
            }
            else if( st.empty() || (c == '}' && st.peek() != '{') ||
                (c == ']' && st.peek() != '[') ||
                (c == ')' && st.peek() != '(')){
                return false;
            }
            else{
                st.pop();
            }
        }
        return st.empty();
    }
}