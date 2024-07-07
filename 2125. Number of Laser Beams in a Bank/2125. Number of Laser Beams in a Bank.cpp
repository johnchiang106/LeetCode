class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0, ans = 0;
        for(auto& b: bank){
            // int num = 0;
            // for(auto& c: b)
            //     if(c == '1') ++num;
            int num = count(b.begin(),b.end(),'1');
            if(num == 0)   continue;
            ans += last * num;
            last = num;
        }
        return ans;
    }
};