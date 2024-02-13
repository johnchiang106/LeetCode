class TrieNode{
public:
    TrieNode* children[26] = {NULL};
    bool isWord = false;
    TrieNode() {}
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    WordDictionary(TrieNode* node) {
        root = node;
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(auto& ch: word){
            if(node->children[ch - 'a'] == NULL){
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return searchDot(word, 0, root);
    }
private:
    TrieNode* root;
    bool searchDot(string& word, int i, TrieNode* node){
        if (i == word.size()) {
            return node->isWord;
        }
        if(word[i] == '.'){
            for(int j = 0; j < 26; ++j){
                if(node->children[j] != NULL && searchDot(word,i+1,node->children[j]))
                    return true;
            }
            return false;
        }
        if(node->children[word[i] - 'a'] == NULL){
            return false;
        }
        return searchDot(word,i+1,node->children[word[i] - 'a']);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */