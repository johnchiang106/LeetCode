class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> exist(256,false);
        int ans = 0, st = 0, ss = s.size();
        for(int i = 0; i < ss; ++i){
            if(exist[s[i]]){
                while(s[st] != s[i]){
                    exist[s[st++]] = false;
                }
                ++st;
            }
            else{
                ans = max(ans,i-st+1);
                exist[s[i]] = true;
            }
            // for(int j = 0; j < 256; ++j)
            //     if(exist[j])    cout<<"1 ";
            //     else    cout<<"0 ";
            // cout<<endl<<st<<" "<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};