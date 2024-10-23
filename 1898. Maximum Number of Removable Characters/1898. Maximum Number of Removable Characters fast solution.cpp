class Solution {
public:

    bool func(int mid, string s, string p, vector<int>& removable){
        for(int i=0;i<mid;i++) s[removable[i]]='*';
        int j=0,k=0;
        while(j<s.size() && k<p.size()){
            if(s[j]==p[k]) k++;
            j++;
        }
        return k==p.size();
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l=0,r=removable.size();
        int ans=0;
        while(l<=r){
            int mid= l + (r-l)/2;
            if(func(mid,s,p,removable)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};