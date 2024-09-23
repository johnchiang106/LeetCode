class Solution {
public:
    int kthGrammar(int n, int k) {
        return helper(k-1);
    }
private:
    bool helper(int num){
        if(num == 0)    return false;
        return helper(num/2) ^ (num&1);
    }
};