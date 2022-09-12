class Solution {
public:
    bool validPalindrome(string str) {
        int left = 0, right = str.size()-1, l2, r2;
        while(str[left] == str[right])
            if(left++ >= right--)    return true;
        
        l2 = left, r2 = right--;
        while(str[left] == str[right])
            if(++left >= --right)    return true;
        
        left = l2+1, right = r2;
        while(str[left] == str[right])
            if(++left >= --right)    return true;
        
        return false;
    }
};