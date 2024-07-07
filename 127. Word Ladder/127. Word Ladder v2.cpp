class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it0 = find(begin(wordList),end(wordList),endWord);
        if(it0 == wordList.end())   return 0;
        
        unordered_set<int> unused;
        vector<vector<int>> ladder;
        
        for(int i = 0; i < wordList.size(); ++i)
            unused.insert(i);
        unused.erase(it0-wordList.begin());
        
        ladder.push_back(vector<int>(1,it0-wordList.begin()));
        while(ladder.back().size() > 0){
            vector<int> v;
            for(auto& i: ladder.back()){
                if(diff1(wordList[i],beginWord))  return ladder.size()+1;
                
                vector<unordered_set<int>::iterator> vec;
                for(auto it = unused.begin(); it != unused.end(); ++it){
                    if(diff1(wordList[i],wordList[*it])){
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