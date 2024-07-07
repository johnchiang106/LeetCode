class Solution {
public:
    bool wordBreak(string str, vector<string>& wordDict) {
        int len = str.size();
        vector<vector<int>> vec(len,vector<int>());
        
        for(string& s: wordDict){
            auto found = str.find(s);
            while(found != str.npos){
                vec[found].push_back(s.size());
                found = str.find(s,found+1);
            }
        }
        if(vec[0].empty())  return false;
        
        stack<pair<int,int>> st;
        st.push({0,0});
        while(!st.empty()){
            int pos = st.top().first;
            if(pos == str.size())   return true;
            
            if(!vec[pos].empty())
                st.push({pos+vec[pos].back(),vec[pos].back()});
            else{
                int prev = pos - st.top().second;
                vec[prev].pop_back();
                st.pop();
            }
        }
        return false;
    }
};