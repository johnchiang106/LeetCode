class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        ans.reserve(n*n);
        string str = "";
        str.reserve(2*n);
        int l = 0, r = 0;
        helper(l,r,str,ans,n);
        return ans;
    }
    void helper(int& left, int& right, string& str, vector<string>& ans, const int& n){
        if(right == n){
            ans.push_back(str);
            return;
        }
        str += "(";
        if(left < n){
            helper(++left,right,str,ans,n);
            --left;
        }
        str.back() = ')';
        if(left > right){
            helper(left,++right,str,ans,n);
            --right;
        }
        str.pop_back();
    }
};