class Solution {
public:
    string longestPalindrome(string s) {
        auto it = s.begin()+1;
        auto itr = s.rend()-1;
        int longest = 1;
        string ans = s.substr(0,1);
        for(; it != s.end(); ++it, --itr){
            bool valid = false;
            auto it2 = it+1;
            auto itr2 = itr;
            for(; it2 != s.end() && itr2 != s.rend(); ++it2, ++itr2){
                // cout<<*it2<<" "<<*itr2<<endl;
                if(*it2 == *itr2) valid = true;
                else    break;
            }
            if(valid && 2*(itr2-itr)+1 > longest){
                longest = 2*(itr2 - itr) + 1;
                ans = s.substr(it2-longest-s.begin(), longest);
                // cout<<ans<<endl;
            }
            else{
                valid = false;
                it2 = it;
                itr2 = itr;
                for(; it2 != s.end() && itr2 != s.rend(); ++it2, ++itr2){
                    // cout<<*it2<<" "<<*itr2<<endl;
                    if(*it2 == *itr2) valid = true;
                    else    break;
                }
                if(valid && 2*(itr2-itr) > longest){
                    longest = 2*(itr2 - itr);
                    ans = s.substr(it2-longest-s.begin(), longest);
                    // cout<<ans<<endl;
                }
            }
        }
        return ans;
    }
};