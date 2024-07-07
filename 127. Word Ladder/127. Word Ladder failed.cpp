class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(begin(wordList),end(wordList),endWord);
        if(it == wordList.end())   return 0;
        
        const int n = wordList.size();
        vector<bool> index(n,false);
        vector<vector<string>> ladder;
        
        index[it-wordList.begin()] = true;
        
        ladder.push_back(vector<string>(1,endWord));
        while(ladder.back().size() > 0){
            vector<string> v;
            for(auto& str: ladder.back()){
                if(diff1(str,beginWord))  return ladder.size()+1;
                
                for(int i = 0; i < n; ++i){
                    if(!index[i] && diff1(str,wordList[i])){
                        v.push_back(wordList[i]);
                    }
                }
            }
            ladder.push_back(v);
        }
        return false;
        
    }
    bool diff1(string& str1, string& str2){
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