class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int rs = removable.size(), ans = 0;
        int l = 0, r = rs, m = (l+r)/2;
        for(int i = 0; i < m; ++i){
            remove.insert(removable[i]);
        }
        while(l <= r){
            m = (r+l)/2;
            if(isSub(s, p)){
                for(int i = m; i < (r+m+1)/2; ++i){
                    remove.insert(removable[i]);
                }
                ans = m;
                l = m+1;
                
            }
            else{
                for(int i = m-1; i >= (l+m-1)/2; --i){
                    remove.erase(removable[i]);
                }
                r = m-1;
            }
        }
        return ans;
    }
private:
    bool isSub(const string& s1, const string& s2){
        int i1 = 0;
        auto i2 = s2.begin();
        while(i2 != s2.end()){
            if(i1 == s1.size())  return false;
            if(remove.count(i1))
                ++i1;
            else if(s1[i1++] == *i2)
                ++i2;
        }
        return true;
    }
    unordered_set<int> remove;
};