class Solution {
public:
    int longestStrChain(vector<string>& words) {
        //build a vector of map, each map contains all the words with same length and its longest string chain
        int l = 0, s = 17;  //1 <= words[i].length <= 16
        for (string& word : words) {
            if(word.size() > l) l = word.size();
            if(word.size() < s) s = word.size();
        }
        vector<map<string,int>> vects;
        for(int i = 0; i <= l - s; i++){
            map<string,int> m;
            vects.push_back(m);
        }
        for (string& word : words) {
            vects[word.size() - s].insert(pair<string, int>(word, 1));
        }
        int longest = 1;
        for(int v = vects.size() - 1; v > 0; v--){
            for(auto& m : vects[v]){
                for(int i = 0; i < m.first.size(); i++){
                    string w = m.first;
                    w.erase(w.begin() + i);
                    if(vects[v-1].find(w) != vects[v-1].end()){
                        vects[v-1][w] = max(vects[v-1][w], m.second+1);
                        longest = max(longest, vects[v-1][w]);
                    }
                }
            }
        }
        return longest;
    }
};