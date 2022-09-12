class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        for(int& n: arr){
            if(m.find(n) == m.end())
                m.insert(pair<int, int>(n, 1));
            else
                m[n]++;
        }
        set<int> s;
        for(auto it = m.begin(); it != m.end(); ++it){
            if(s.find(it->second) == s.end())
                s.insert(it->second);
            else
                return false;
        }
        return true;
    }
};