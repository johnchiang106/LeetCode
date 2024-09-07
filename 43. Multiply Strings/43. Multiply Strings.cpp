class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")  return "0";
        if(num1.size() < num2.size())   swap(num1, num2);
        int s1 = num1.size(), s2 = num2.size();
        if(s1+s2 < 19)
            return to_string(stoll(num1)*stoll(num2));
        
        int l = (s1+s2)/sDigit + 1;
        vector<int> seg(l, 0), seg1, seg2;
        int l1 = calSeg(num1, seg1), l2 = calSeg(num2, seg2);

        for(int j = 0; j < l2; ++j){
            int& n2 = seg2[j];
            for(int i = 0; i < l1; ++i){
                long long n = (long long)seg1[i] * n2;
                seg[i+j] += n % sSize;
                if(n > sSize)
                    seg[i+j+1] += n / sSize;
            }
        }
        for(int i = 0; i < l-1; ++i){
            if(seg[i] < sSize)  continue;
            seg[i+1] += seg[i] / sSize;
            seg[i] %= sSize;
        }
        if(seg.back() == 0) seg.pop_back();

        string ans = "";
        ans.reserve(s1+s2);
        for(auto i = seg.rbegin(); i != seg.rend(); ++i){
            if(!ans.empty() && *i < sSize/10){
                int count = sSize / 10;
                while(*i < count){
                    ans.push_back('0');
                    count /= 10;
                }
            }
            ans += to_string(*i);
        }
        return ans;
    }
    int calSeg(string& num, vector<int>& seg){
        int s = num.size();
        seg.reserve(s/sDigit+1);
        for(int i = sDigit; i <= s; i += sDigit)
            seg.push_back(stoll(num.substr(s-i, sDigit)));
        if(s & 7)
            seg.push_back(stoll(num.substr(0, s%sDigit)));
        return seg.size();
    }
private:
    const int sDigit = 8;
    const int sSize = 100000000;
};