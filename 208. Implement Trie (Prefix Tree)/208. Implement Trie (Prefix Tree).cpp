class TrieNode{
public:
    TrieNode* children[26] = {NULL};
    bool isWord = false;
    TrieNode() {}
};
class Trie {
public:
    Trie() {}
    
    void insert(string word) {
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
        TrieNode* node = root;
        for(auto& ch: word){
            if(node->children[ch - 'a'] == NULL){
                return false;
            }
            node = node->children[ch - 'a'];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto& ch: prefix){
            if(node->children[ch - 'a'] == NULL){
                return false;
            }
            node = node->children[ch - 'a'];
        }
        return true;
    }
private:
    TrieNode* root = new TrieNode();
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */