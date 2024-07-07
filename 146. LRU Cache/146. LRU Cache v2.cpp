class LRUCache {
public:
    LRUCache(int capacity) :c(capacity) {}
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        if(q.empty() || q.back() != key){
            ++cache[key].second;
            q.push(key);
        }
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end() && cache.size() >= c){
            while(--cache[q.front()].second != 0)
                q.pop();
            cache.erase(q.front());
            q.pop();
        }
        cache[key].first = value;
        if(q.empty() || q.back() != key){
            ++cache[key].second;
            q.push(key);
        }
        return;
    }
    unordered_map<int, pair<int,int>> cache;    // <key, <value,count>>
    queue<int> q;
    int c;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */