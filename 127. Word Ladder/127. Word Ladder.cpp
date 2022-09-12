class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {        
        unordered_set<string> unused;
        vector<vector<string>> ladder;
        
        for(auto& str: wordList)
            unused.insert(str);
        if(find(begin(unused),end(unused),endWord) == unused.end()) return 0;
        unused.erase(endWord);
        
        ladder.push_back(vector<string>(1,endWord));
        while(ladder.back().size() > 0){
            vector<string> v;
            for(auto& str: ladder.back()){
                if(diff1(str,beginWord))  return ladder.size()+1;
                
                vector<unordered_set<string>::iterator> vec;
                for(auto it = unused.begin(); it != unused.end(); ++it){
                    if(diff1(str,*it)){
                        v.push_back(*it);
                        vec.push_back(it);
                    }
                }
                for(auto& it: vec)   unused.erase(it);
            }
            ladder.push_back(v);
        }
        return false;
        
    }
    bool diff1(string& str1, string str2){
        bool d = false;
        for(int i = 0; i < str1.size(); ++i){
            if(str1[i] != str2[i]){
                if(d)   return false;
                else    d = true;
            }
        }
        if(d)   return true;
        return false;
    }
};