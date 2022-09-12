class Solution {
public:
    static bool cmp(const pair<string, int>& x, const pair<string, int>& y) {
        // if(x.second != y.second) return x.second > y.second;
        // else    return x.first < y.first;
        return x.second > y.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for(string& str: words){
            m[str]++;
        }
        
        vector<pair<string, int>> v;
        for (auto p : m) {
            v.push_back(p);
        }
        stable_sort(begin(v), end(v), cmp);
        
        vector<string> ans;
        for(auto i = v.begin(); i != v.begin() + k; i++){
            ans.push_back((*i).first);
        }
        return ans;
    }
};