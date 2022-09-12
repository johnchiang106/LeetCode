class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        stack<pair<int,int>> st;
        st.push({0,0});

        while(st.size() > 0){
            pair<int,int>& p = st.top();
            if(p.first < n){
              st.push({p.first+1, p.second});
              str+="(";
            }
            else{
              for(int i = p.second; i < n; i++) str+=")";
              ans.push_back(str);

              do{
                st.pop();
                p = st.top();
                st.top().second += 1;

                while(str.back() == ')')  str.pop_back();
                str.pop_back();
                str += ")";
              }while(p.second+1 > p.first && p.first != 0);

              if(p.first == 0)  break;
            }
        }
        return ans;
    }
};