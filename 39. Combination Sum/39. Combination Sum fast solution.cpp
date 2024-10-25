class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    vector<int>cur;
    void rec(int k,vector<int>& c,int sum,int x){
        if(sum==x){
            if(st.find(cur)==st.end()){
                ans.push_back(cur);
                st.insert(cur);
            }
            return;
        }
        for(int i=k;i<c.size();i++){
            if(sum+c[i]<=x){
                cur.push_back(c[i]);
                rec(i,c,sum+c[i],x);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        rec(0,c,0,t);
        return ans;
        
    }
};