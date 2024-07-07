map<char,int> m;
class Solution {
public:
    string frequencySort(string s) {
        m.clear();
        for(auto& c: s) m[c]++;
        for(auto& p: m){
            m[p.first] *= 75;
            m[p.first] -= p.first;
        }
        sort(s.begin(),s.end(),cmp);
        return s;
    }
private:
    static bool cmp(char a, char b){
       return m[a] > m[b];
    }
};