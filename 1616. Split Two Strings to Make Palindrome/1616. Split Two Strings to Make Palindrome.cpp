class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return checkPalindrome(a, b) || 
            checkPalindrome(b, a);
    }
private:
    bool checkPalindrome(const string& a, const string& b) {
        const int n = a.size();
        int i = 0, j = n-1;
        while(i < j){
            if(a[i] != b[j]){
                return isPalindrome(a.substr(i,n-i*2)) || 
                   isPalindrome(b.substr(i,n-i*2));
            }
            ++i, --j;
        }
        return true;
    }
    bool isPalindrome(const string& s){
        int i = 0, j = s.size()-1;
        while(i < j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
};